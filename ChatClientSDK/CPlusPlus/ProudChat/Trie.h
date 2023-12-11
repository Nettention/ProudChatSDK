#pragma once
#include <string>

namespace ProudChat {
	class CTrieNode;
	class CTrie
	{
	private:
		CTrieNode* root = nullptr;

	public :
		CTrie();
		virtual ~CTrie();

	public :
		void InsertWord(const std::wstring& word);
		bool searchWord(const std::wstring& word);
	};
}

