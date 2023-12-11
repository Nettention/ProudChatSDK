#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>

namespace ProudChat {
	class CFileSync
	{
	public:
		static const std::wstring GetCDNFile(const std::wstring& cdnUrl, const std::wstring& saveFilePath);
	};
}