#include "Filtering.h"
#include "Trie.h"
#include <sstream>
#include "PNString.h"

ProudChat::CFiltering::CFiltering()
{

}

ProudChat::CFiltering::~CFiltering()
{
	RemoveFiltering();
}

void ProudChat::CFiltering::FilteringText(Proud::String& text)
{
#if PLATFORM_WINDOWS
	FString textMsg = WCHAR_TO_TCHAR(text.c_str());
#elif PLATFORM_ANDROID
	FString textMsg = UTF8_TO_TCHAR(text.c_str());
#endif

	std::wstring convertMsg = TCHAR_TO_WCHAR(*textMsg);

	if (nullptr == m_Trie) return;

	for (size_t i = 0; i < text.GetLength(); ++i) {
		std::wstring word;
		for (size_t j = i; j < text.GetLength(); ++j) {
			word += text[j];

			if (m_Trie->searchWord(word)) {
				std::wstring replacement(j - i + 1, '*');

				convertMsg.replace(i, j - i + 1, replacement);
				//text.Replace(word.c_str(), replacement.c_str());
				i = j;
				break;
			}
		}
	}
	textMsg = WCHAR_TO_TCHAR(convertMsg.c_str());

#if PLATFORM_WINDOWS
	text = TCHAR_TO_WCHAR(*textMsg);
#elif PLATFORM_ANDROID
	text =  TCHAR_TO_UTF8(*textMsg);
#endif
}

void ProudChat::CFiltering::AddFiltering(const std::wstring& filter)
{
	if (nullptr == m_Trie)
		m_Trie = new CTrie();

	// wstring을 wstringstream에 넣어줍니다.
	std::wstringstream wss(filter);

	// 라인을 읽어옵니다.
	std::wstring line;
	while (std::getline(wss, line)) {
		// 쉼표(,)를 구분자로 사용하여 토큰을 추출하고 벡터에 저장합니다.
		std::wstringstream lineStream(line);
		std::wstring token;
		while (std::getline(lineStream, token, L',')) {
			m_Trie->InsertWord(token);
		}
	}
}

void ProudChat::CFiltering::RemoveFiltering()
{
	if (nullptr != m_Trie) {
		delete m_Trie;
		m_Trie = nullptr;
	}
}
