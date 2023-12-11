#include "Filtering.h"
#include "Trie.h"
#include <sstream>

ProudChat::CFiltering::CFiltering()
{

}

ProudChat::CFiltering::~CFiltering()
{
	RemoveFiltering();
}

void ProudChat::CFiltering::FilteringText(Proud::String& text)
{
	if (nullptr == m_Trie) return;

	for (size_t i = 0; i < text.GetLength(); ++i) {
		std::wstring word;
		for (size_t j = i; j < text.GetLength(); ++j) {
			word += text[j];

			if (m_Trie->searchWord(word)) {
				std::wstring replacement(j - i + 1, '*');

				text.Replace(word.c_str(), replacement.c_str());
				i = j;
				break;
			}
		}
	}
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
