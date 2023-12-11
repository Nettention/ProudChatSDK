#include "FileSync.h"
#include "Misc/FileHelper.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpModule.h"

FString Proud::CFileSync::SaveFilePath = "";
bool Proud::CFileSync::bRequestComplete = false;
bool Proud::CFileSync::bDownloadSuccess = false;

FString Proud::CFileSync::GetCDNFile(const FString& CdnUrl, const FString& InSaveFilePath)
{
    SaveFilePath = InSaveFilePath;

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->OnProcessRequestComplete().BindStatic(&CFileSync::OnRequestComplete);
    HttpRequest->SetURL(CdnUrl);
    HttpRequest->SetVerb(TEXT("GET"));
    HttpRequest->ProcessRequest();

    while (!bRequestComplete) {
        FPlatformProcess::Sleep(0.1f);
    }

    if (bDownloadSuccess) {
        FString FileContent;
        if (FFileHelper::LoadFileToString(FileContent, *SaveFilePath)) {
            return FileContent;
        }
        else {
            UE_LOG(LogTemp, Error, TEXT("파일을 읽는 데 실패했습니다: %s"), *SaveFilePath);
        }
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("파일 다운로드 실패!"));
    }

    return FString();
}

void Proud::CFileSync::OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
    if (bSuccess && Response.IsValid() && Response->GetResponseCode() == EHttpResponseCodes::Ok)
    {
        bDownloadSuccess = FFileHelper::SaveStringToFile(Response->GetContentAsString(), *SaveFilePath);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("HTTP 요청 실패!"));
    }

    bRequestComplete = true;
}
