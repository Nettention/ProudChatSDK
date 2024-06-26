#include "FileSync.h"
#include "Misc/FileHelper.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpModule.h"
#include "HAL/PlatformProcess.h"
#include "Logging/LogMacros.h"
#include "HttpManager.h"

FString Proud::CFileSync::SaveFilePath = "";
bool Proud::CFileSync::bRequestComplete = false;
bool Proud::CFileSync::bDownloadSuccess = false;

FString Proud::CFileSync::GetCDNFile(const FString& CdnUrl, const FString& InSaveFilePath)
{
    SaveFilePath = InSaveFilePath;
    bRequestComplete = false;
    bDownloadSuccess = false;

    // HttpModule 초기화 확인
    if (!FHttpModule::Get().IsHttpEnabled())
    {
        UE_LOG(LogTemp, Error, TEXT("HTTP is not enabled"));
        return FString();
    }

    FHttpModule* Http = &FHttpModule::Get();
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();

    HttpRequest->OnProcessRequestComplete().BindStatic(&Proud::CFileSync::OnRequestComplete);
    HttpRequest->OnRequestProgress().BindStatic(&Proud::CFileSync::OnRequestProgress);
    HttpRequest->SetURL(CdnUrl);
    HttpRequest->SetVerb(TEXT("GET"));

    // HTTP 요청 전송 시도
    if (!HttpRequest->ProcessRequest())
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to process HttpRequest"));
        return FString();
    }

    UE_LOG(LogTemp, Log, TEXT("HTTP request sent to %s"), *CdnUrl);

    float lastTime = FPlatformTime::Seconds();
    while (!bRequestComplete)
    {
        float curTime = FPlatformTime::Seconds();
        FHttpModule::Get().GetHttpManager().Tick(curTime - lastTime);
        FPlatformProcess::Sleep(0.01f);
        lastTime = curTime;
    }

	if (bDownloadSuccess)
	{
		FString FileContent;
		if (FFileHelper::LoadFileToString(FileContent, *SaveFilePath))
		{
			UE_LOG(LogTemp, Log, TEXT("File downloaded and read successfully"));
			return FileContent;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to read file: %s"), *SaveFilePath);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("File download failed!"));
	}

    return FString();
}

void Proud::CFileSync::OnRequestProgress(FHttpRequestPtr RequestPtr, int32 SendBytes, int32 RecvBytes)
{
    if (RequestPtr.IsValid() && RequestPtr->GetResponse().IsValid())
    {
        int32 TotalSize = RequestPtr->GetResponse()->GetContentLength();
        float Percent = (float)RecvBytes / TotalSize;
        UE_LOG(LogTemp, Log, TEXT("Download Progress: %f"), Percent);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid request or response in OnRequestProgress"));
    }
}

void Proud::CFileSync::OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
    UE_LOG(LogTemp, Log, TEXT("OnRequestComplete called"));

    if (bSuccess && Response.IsValid() && Response->GetResponseCode() == EHttpResponseCodes::Ok)
    {
        bDownloadSuccess = FFileHelper::SaveStringToFile(Response->GetContentAsString(), *SaveFilePath);
        if (bDownloadSuccess)
        {
            UE_LOG(LogTemp, Log, TEXT("HTTP request succeeded and file saved"));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to save file: %s"), *SaveFilePath);
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("HTTP request failed or response invalid!"));
    }

    bRequestComplete = true;
}
