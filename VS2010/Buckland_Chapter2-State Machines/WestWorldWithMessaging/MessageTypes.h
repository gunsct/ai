#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_HiElasImLonly,
  Msg_HiMoeImLonly,
  Msg_CutCall,
  Msg_HiMoe,
  Msg_WelcomBob,
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

  case Msg_HiElasImLonly:
	  return "HiElasImLonly";

  case Msg_HiMoeImLonly:
	  return "Msg_HiMoeImLonly";

  case Msg_CutCall:
	  return "CutCall";

  case Msg_HiMoe:
	  return "HiMoe";

  case Msg_WelcomBob:
	  return "WelcomBob";

  default:

    return "Not recognized!";
  }
}

#endif