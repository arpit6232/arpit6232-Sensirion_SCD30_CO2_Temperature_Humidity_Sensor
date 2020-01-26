#ifndef _ROS_marble_origin_detection_msgs_OriginDetectionStatus_h
#define _ROS_marble_origin_detection_msgs_OriginDetectionStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace marble_origin_detection_msgs
{

  class OriginDetectionStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _status_type;
      _status_type status;
      enum { NO_ORIGIN_FOUND = 0 };
      enum { GATE_FOUND = 1 };
      enum { GATE_AND_DISTAL_FOUND = 2 };
      enum { GATE_FOUND_DISTAL_ABANDONED = 3 };

    OriginDetectionStatus():
      header(),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return "marble_origin_detection_msgs/OriginDetectionStatus"; };
    const char * getMD5(){ return "28566714ddda209ef27dc772fbd83e0b"; };

  };

}
#endif
