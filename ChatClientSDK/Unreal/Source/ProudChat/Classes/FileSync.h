#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"

namespace Proud {

	class CFileSync
	{
	public:
		static FString GetCDNFile(const FString& CdnUrl, const FString& SaveFilePath);

	private:
		static void OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

		static FString SaveFilePath;
		static bool bRequestComplete;
		static bool bDownloadSuccess;
	};

}
