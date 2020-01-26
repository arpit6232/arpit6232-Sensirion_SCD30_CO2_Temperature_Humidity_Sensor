#ifndef _ROS_SERVICE_StartTracking_h
#define _ROS_SERVICE_StartTracking_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltf
{

static const char STARTTRACKING[] = "ltf/StartTracking";

  class StartTrackingRequest : public ros::Msg
  {
    public:
      typedef uint8_t _prismType_type;
      _prismType_type prismType;

    StartTrackingRequest():
      prismType(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->prismType >> (8 * 0)) & 0xFF;
      offset += sizeof(this->prismType);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->prismType =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->prismType);
     return offset;
    }

    const char * getType(){ return STARTTRACKING; };
    const char * getMD5(){ return "867c2853c0fb2f32030694c5e6914892"; };

  };

  class StartTrackingResponse : public ros::Msg
  {
    public:
      typedef uint16_t _rc_type;
      _rc_type rc;

    StartTrackingResponse():
      rc(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->rc >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rc >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->rc =  ((uint16_t) (*(inbuffer + offset)));
      this->rc |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->rc);
     return offset;
    }

    const char * getType(){ return STARTTRACKING; };
    const char * getMD5(){ return "353a2961a33a47b4b5d08eaed4d64e88"; };

  };

  class StartTracking {
    public:
    typedef StartTrackingRequest Request;
    typedef StartTrackingResponse Response;
  };

}
#endif
