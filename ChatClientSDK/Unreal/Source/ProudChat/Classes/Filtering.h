#pragma once
#include <string>
#include "CoreMinimal.h"

#include "ProudNetCommon.h"

namespace ProudChat
{
	class CTrie;
	class CFiltering
	{
	private:
		CTrie* m_Trie = nullptr;

	public:
		CFiltering();
		~CFiltering();

	public:
		void FilteringText(Proud::String& text);
		void AddFiltering(const std::wstring& filter);


		void RemoveFiltering();

	};
}
