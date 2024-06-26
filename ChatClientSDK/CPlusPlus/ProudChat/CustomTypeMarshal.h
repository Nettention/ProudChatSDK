#pragma once

enum MsgType {
	Direct = 1,
	Channel = 2,
	Notice = 3,
};

inline Proud::String ToString(MsgType type) {
	switch (type) {
	case Direct: return _PNT("Send");
	case Channel: return _PNT("Channel");
	case Notice: return _PNT("Notice");
	default: return _PNT("MsgType Unknown");
	}
}

PROUDNET_SERIALIZE_ENUM(MsgType)

struct tagMsgRecord {
	uint64_t timestamp = 0;
	Proud::String src = _PNT("");
	Proud::String dest = _PNT("");
	Proud::String message = _PNT("");
};

struct tagMsgRecords {
	MsgType msgType;
	Proud::CFastArray<tagMsgRecord> records;

};

namespace Proud {
	inline CMessage& operator >> (CMessage& a, tagMsgRecord& msgRecord) {
		a >> msgRecord.timestamp;
		a >> msgRecord.src;
		a >> msgRecord.dest;
		a >> msgRecord.message;

		return a;
	}
	inline CMessage& operator << (CMessage& a, const tagMsgRecord& msgRecord) {
		a << msgRecord.timestamp;
		a << msgRecord.src;
		a << msgRecord.dest;
		a << msgRecord.message;
		return a;
	}
	inline void AppendTextOut(String& a, const tagMsgRecord& b) {
		String xx;
		xx.Format(L"{timestamp=%s , src=%s , dest=%s , message=%s}", b.timestamp , b.src , b.dest , b.message);
		a += xx;
	}

	inline CMessage& operator >> (CMessage& a, tagMsgRecords& msgRecords) {
		a >> msgRecords.msgType;
		a >> msgRecords.records;
		
		//intptr_t count;
		//a >> count;

		//for (intptr_t i = 0; i < count; ++i) {
		//	tagMsgRecord msgRecord;
		//	a >> msgRecord;
		//	msgRecords.records.Add(msgRecord);
		//}
		return a;
	}
	inline CMessage& operator << (CMessage& a, const tagMsgRecords& msgRecords) {
		a << msgRecords.msgType;
		a << msgRecords.records;
		//a << msgRecords.records.Count;
		//for (auto iter = msgRecords.records.begin(); iter != msgRecords.records.end(); ++iter)
		//	a << *iter;
		return a;
	}
	inline void AppendTextOut(String& a, const tagMsgRecords& b) {
		String xx;
		xx.Format(L"{msgType=%s}" , ToString(b.msgType));
		a += xx;

		for(auto iter = b.records.begin() ; iter != b.records.end() ; ++iter)
			AppendTextOut(a, *iter);
	}
}