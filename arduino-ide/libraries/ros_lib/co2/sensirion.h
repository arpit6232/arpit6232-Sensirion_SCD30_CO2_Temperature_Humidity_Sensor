#ifndef _ROS_co2_sensirion_h
#define _ROS_co2_sensirion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace co2
{

  class sensirion : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _carbon_dioxide_type;
      _carbon_dioxide_type carbon_dioxide;
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef float _humidity_type;
      _humidity_type humidity;

    sensirion():
      header(),
      carbon_dioxide(0),
      temperature(0),
      humidity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->carbon_dioxide);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      offset += serializeAvrFloat64(outbuffer + offset, this->humidity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->carbon_dioxide));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->humidity));
     return offset;
    }

    const char * getType(){ return "co2/sensirion"; };
    const char * getMD5(){ return "182b31636773c4eadbeadb7d55d6e144"; };

  };

}
#endif
