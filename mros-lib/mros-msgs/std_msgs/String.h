#ifndef _STD_MSGS_STRING_
#define _STD_MSGS_STRING_


static const int STRING_MSG_ID = 9;

namespace std_msgs{
class String{
public:
	std::string data;
  int dataSize(){return data.size() + 4;}

  void memCopy(char *addrPtr){
    int size;
    size = data.size();
    memcpy(addrPtr, &size, 4);
    addrPtr += 4;
    memcpy(addrPtr, data.c_str(), size);
  }
};
}

namespace message_traits
{
template<>
struct MD5Sum<STRING_MSG_ID>
{
  static const char* value()
  {
    return "992ce8a1687cec8c8bd883ec73ca41d1";
  }

};

template<>
struct DataType<std_msgs::String*>
{
  static const char* value()
  {
    return "std_msgs/String";
  }

};

template<>
struct DataTypeId<std_msgs::String*>
{
  static const int value()
  {
    return STRING_MSG_ID;
  }

};

template<>
struct Definition<std_msgs::String*>
{
	static const char* value()
	{
		return "string data\n\
";
	}
};

}

namespace subtask_methods
{
  template<>
  struct CallCallbackFuncs<STRING_MSG_ID>{
    static void call(void (*fp)(intptr_t), char *rbuf)
    {
      std_msgs::String msg;
      msg.data = &rbuf[8];
      fp(&msg);
    }
  };
}

#endif