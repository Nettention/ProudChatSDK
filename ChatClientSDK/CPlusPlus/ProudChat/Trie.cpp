#include "Trie.h"
#include "TrieNode.h"

ProudChat::CTrie::CTrie()
{
	root = new ProudChat::CTrieNode();
}

ProudChat::CTrie::~CTrie()
{
	if (nullptr != root)
	{
		delete root;
		root = nullptr;
	}
}

void ProudChat::CTrie::InsertWord(const std::wstring& word)
{
	CTrieNode* node = root;

	for (wchar_t c : word) {
		if (nullptr == node) return;
		if (false == node->isChildren(c))
			node->AddChildren(c);

		node = node->GetChildren(c);

	}

	if (node != nullptr && node != root)
		node->SetIsEndOfWord(true);

}

bool ProudChat::CTrie::searchWord(const std::wstring& word)
{
	CTrieNode* node = root;
	for (wchar_t c : word) {
		if (nullptr == node ) return false;
		if (false == node->isChildren(c)) return false;
		if (true == node->GetIsEndOfWord()) return true;
		node = node->GetChildren(c);
	}
	return node->GetIsEndOfWord();

	return true;
}
