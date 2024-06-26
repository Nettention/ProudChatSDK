#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "UObject/NoExportTypes.h"

namespace Proud {
	class CFileSync
	{
	public:
		static FString GetCDNFile(const FString& CdnUrl, const FString& SaveFilePath);

	private:
		static void OnRequestProgress(FHttpRequestPtr RequestPtr, int32 SendBytes, int32 RecvBytes);
		static void OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

		static FString SaveFilePath;
		static bool bRequestComplete;
		static bool bDownloadSuccess;
		static FEvent* RequestCompleteEvent;
	};
}