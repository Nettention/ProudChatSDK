
#include "FileSync.h"
#include <string>
#include <locale>
#include <codecvt>
#include <sstream>

const std::wstring ProudChat::CFileSync::GetCDNFile(const std::wstring& cdnUrl, const std::wstring& saveFilePath)
{
	// curl을 사용하여 파일 다운로드
	std::wstring downloadCommand = L"curl -o " + saveFilePath + L" " + cdnUrl;
	int downloadResult = _wsystem(downloadCommand.c_str());

	if (downloadResult == 0) {
		std::wcout << L"파일 다운로드 성공!" << std::endl;

		// 다운로드된 파일을 읽음
		std::wifstream file(saveFilePath);
		if (file.is_open()) {
			file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
			std::wstringstream wss;
			wss << file.rdbuf();
			return wss.str();
		}
		else {
			std::wcerr << L"파일을 읽을 수 없습니다." << std::endl;
		}
	}
	else {
		std::wcerr << L"파일 다운로드 실패!" << std::endl;
	}
	return L"";
}
