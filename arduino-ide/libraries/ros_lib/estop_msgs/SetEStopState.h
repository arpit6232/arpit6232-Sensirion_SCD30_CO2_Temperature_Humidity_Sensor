#ifndef _ROS_SERVICE_SetEStopState_h
#define _ROS_SERVICE_SetEStopState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace estop_msgs
{

static const char SETESTOPSTATE[] = "estop_msgs/SetEStopState";

  class SetEStopStateRequest : public ros::Msg
  {
    public:
      typedef bool _estop_enabled_type;
      _estop_enabled_type estop_enabled;

    SetEStopStateRequest():
      estop_enabled(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_estop_enabled;
      u_estop_enabled.real = this->estop_enabled;
      *(outbuffer + offset + 0) = (u_estop_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop_enabled);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_estop_enabled;
      u_estop_enabled.base = 0;
      u_estop_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estop_enabled = u_estop_enabled.real;
      offset += sizeof(this->estop_enabled);
     return offset;
    }

    const char * getType(){ return SETESTOPSTATE; };
    const char * getMD5(){ return "183cb7e2d6a0d66222c8155d602c050e"; };

  };

  class SetEStopStateResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    SetEStopStateResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return SETESTOPSTATE; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SetEStopState {
    public:
    typedef SetEStopStateRequest Request;
    typedef SetEStopStateResponse Response;
  };

}
#endif
