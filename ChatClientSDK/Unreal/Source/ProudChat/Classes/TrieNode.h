#pragma once
#include <unordered_map>
namespace ProudChat
{
	class CTrieNode
	{
	private:
		std::unordered_map<wchar_t, CTrieNode*> children;
		bool isEndOfWord = false;

	public:
		CTrieNode();
		~CTrieNode();

	public:
		void SetIsEndOfWord(bool value);
		bool GetIsEndOfWord();

		CTrieNode* AddChildren(const wchar_t word);
		CTrieNode* GetChildren(const wchar_t word);

		bool isChildren(const wchar_t word);
	};
}

