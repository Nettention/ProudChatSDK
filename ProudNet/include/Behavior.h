﻿/*
ProudNet 1.8.00002-master


이 프로그램의 저작권은 넷텐션에게 있습니다.
이 프로그램의 수정, 사용, 배포에 관련된 사항은 본 프로그램의 소유권자와의 계약을 따르며,
계약을 준수하지 않는 경우 원칙적으로 무단 사용을 금지합니다.
무단 사용에 의한 책임은 본 프로그램의 소유권자와의 계약서에 명시되어 있습니다.

** 주의 : 저작물에 관한 위의 명시를 제거하지 마십시오.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


此程序的版权归Nettention公司所有。
与此程序的修改、使用、发布相关的事项要遵守此程序的所有权者的协议。
不遵守协议时要原则性的禁止擅自使用。
擅自使用的责任明示在与此程序所有权者的合同书里。

** 注意：不要移除关于制作物的上述明示。


このプログラムの著作権はNettentionにあります。
このプログラムの修正、使用、配布に関する事項は本プログラムの所有権者との契約に従い、
契約を遵守しない場合、原則的に無断使用を禁じます。
無断使用による責任は本プログラムの所有権者との契約書に明示されています。

** 注意：著作物に関する上記の明示を除去しないでください。

*/

#pragma once

#include "Message.h"
#include "HlaDef.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	template<typename type>
	class CStaticBehaviorMember
	{
		type m_value_INTERNAL;
	public:
		inline void Set(type value)
		{
			m_value_INTERNAL = value;
		}
		inline type Get()
		{
			return m_value_INTERNAL;
		}

		// does nothing, but it is needed because it is called by SWD compiler output.
		// \return always false
		inline bool GatherTheChangeToMessage(HlaFieldGroupID memberID, CMessage &outputMessage, Protocol &outProtocol)
		{
			outProtocol = Protocol_Undefined;
			return false;
		}

		inline void ClearTheChange()
		{
		}

		inline bool IsChanged()
		{
			return false;
		}

		// does nothing, but it is needed because it is called by SWD compiler output.
		inline void GatherAllToMessage(HlaFieldGroupID memberID, CMessage &outputMessage)
		{
		}
	};

	/** 
	\~korean
	Conditional behavior member를 위한 임시 Class
	
	\~english
	a template class for conditional behavior member
	
	\~chinese
	为了Conditional behavior member的临时Class。
	
	\~japanese
	Conditional behavior memberのための臨時クラス
	\~
	*/
	template<typename type>
	class CConditionalBehaviorMember
	{
		type m_value_INTERNAL;
		bool m_valueChanged_INTERNAL;
	public:
		inline CConditionalBehaviorMember()
		{
			m_valueChanged_INTERNAL = false;
		}
		inline void Set(type value)
		{
			if (value != m_value_INTERNAL)
			{
				// A variable whose 'changed'
				// is true will be multicasted soon.
				m_valueChanged_INTERNAL = true;
				m_value_INTERNAL = value;
			}
		}
		inline type Get()
		{
			return m_value_INTERNAL;
		}

		// append the value to the message if it has been changed.
		// \return true if the value is written to the message.
		inline bool GatherTheChangeToMessage(HlaFieldGroupID memberID, CMessage &outputMessage, Protocol &outProtocol)
		{
			outProtocol = Protocol_Undefined;
			if (m_valueChanged_INTERNAL)
			{
				outputMessage.Write(memberID);
				outputMessage<<m_value_INTERNAL;
				outProtocol = Protocol_ReliableSend;

				return true;
			}

			return false;
		}

		inline void ClearTheChange()
		{
			m_valueChanged_INTERNAL = false;
		}

		inline bool IsChanged()
		{
			return m_valueChanged_INTERNAL;
		};

		// does nothing, but it is needed because it is called by SWD compiler output.
		inline void GatherAllToMessage(HlaFieldGroupID memberID, CMessage &outputMessage)
		{
			outputMessage.Write(memberID);
			outputMessage<<m_value_INTERNAL;
		}
	};

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif