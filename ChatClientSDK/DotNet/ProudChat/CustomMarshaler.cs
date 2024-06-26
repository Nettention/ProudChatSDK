using Nettention.Proud;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Channels;
using System.Text;
using System.Threading.Tasks;

public enum MsgType
{
    None = 0,
    Direct = 1,
    Channel = 2,
    Notice = 3,
};

//Proud::String ToString(MsgType type)
//{
//    switch (type)
//    {
//        case Direct: return _PNT("Send");
//        case Channel: return _PNT("Channel");
//        case Notice: return _PNT("Notice");
//        default: return _PNT("MsgType Unknown");
//    }
//}

//PROUDNET_SERIALIZE_ENUM(MsgType)

public class tagMsgRecord
{
    public UInt64 timestamp = 0;
    public System.String src = "";
    public System.String dest = "";
    public System.String message = "";
};

public class tagMsgRecords
{
    public MsgType msgType = MsgType.None;
    public System.Collections.Generic.List<tagMsgRecord> records = new System.Collections.Generic.List<tagMsgRecord>();
};


namespace ProudChat
{
    class CustomMarshaler : Nettention.Proud.Marshaler
    {
        public static bool Read(Message msg , out tagMsgRecord record)
        {
            record = new tagMsgRecord();
            if (!msg.Read(out record.timestamp)) { return false; }
            if (!msg.Read(out record.src)) { return false; }
            if (!msg.Read(out record.dest)) { return false; }
            if (!msg.Read(out record.message)) { return false; }
            return true;
        }
        public static bool Read(Message msg , out tagMsgRecords records)
        {
            records = new tagMsgRecords();
            Int32 msgType = 0 ;
            if(!msg.Read(out msgType)) return false;
            records.msgType = (MsgType)msgType;

            long length = 0;
            if(!msg.ReadScalar(ref length)) return false;
            records.records = new List<tagMsgRecord>();
            for(int i = 0; i < length; ++i)
            {
                tagMsgRecord record;
                Read(msg, out record);
                records.records.Add(record);
            }
            return true;
        }

        public static void Write(Message msg , tagMsgRecords records)
        {
            return;
        }
        public static void Write(Message msg, tagMsgRecord record)
        {
            return;
        }
        public static bool Read(Message msg, out List<System.String> strList)
        {
            strList = null;
            long size = 0;
            if (!msg.ReadScalar(ref size))
            {
                return false;
            }
            strList = new List<System.String>();
            for (int i = 0; i < size; ++i)
            {
                System.String s;
                if (!msg.Read(out s))
                {
                    return false;
                }
                strList.Add(s);
            }
            return true;
        }

        public static void Write(Message msg, List<System.String> strList)
        {
            msg.WriteScalar(strList.Count);
            for (int i = 0; i < strList.Count; ++i)
            {
                msg.Write(strList[i]);
            }
        }
    }
}
