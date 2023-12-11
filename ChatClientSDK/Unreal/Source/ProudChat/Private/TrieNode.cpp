#include "TrieNode.h"

ProudChat::CTrieNode::CTrieNode()
{

}

ProudChat::CTrieNode::~CTrieNode()
{
	std::unordered_map<wchar_t, CTrieNode*>::iterator iter = children.begin();
	std::unordered_map<wchar_t, CTrieNode*>::iterator iterEnd = children.end();
	for (;iter != iterEnd ; ++iter)
	{
		delete iter->second;
		iter->second = nullptr;
	}
	
	children.clear();
}

void ProudChat::CTrieNode::SetIsEndOfWord(bool value)
{
	isEndOfWord = value;
}

bool ProudChat::CTrieNode::GetIsEndOfWord()
{
	return isEndOfWord;
}

ProudChat::CTrieNode* ProudChat::CTrieNode::AddChildren(const wchar_t word)
{
	if (children.end() == children.find(word))
		children.insert(std::unordered_map<wchar_t, CTrieNode*>::value_type(word, new CTrieNode()));
	return children[word];
}

ProudChat::CTrieNode* ProudChat::CTrieNode::GetChildren(const wchar_t word)
{
	if (children.end() != children.find(word))
		return children[word];
	return nullptr;
}

bool ProudChat::CTrieNode::isChildren(const wchar_t word)
{
	return children.end() != children.find(word);
}
