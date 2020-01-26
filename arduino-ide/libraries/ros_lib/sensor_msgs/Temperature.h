#ifndef _ROS_sensor_msgs_Temperature_h
#define _ROS_sensor_msgs_Temperature_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sensor_msgs
{

  class Temperature : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef float _variance_type;
      _variance_type variance;
      typedef float _co2_type;
      _co2_type co2;
      typedef float _humidity_type;
      _humidity_type humidity;

    Temperature():
      header(),
      temperature(0),
      variance(0),
      co2(0),
      humidity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      offset += serializeAvrFloat64(outbuffer + offset, this->variance);
      offset += serializeAvrFloat64(outbuffer + offset, this->co2);
      offset += serializeAvrFloat64(outbuffer + offset, this->humidity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->variance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->co2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->humidity));
     return offset;
    }

    const char * getType(){ return "sensor_msgs/Temperature"; };
    const char * getMD5(){ return "ff71b307acdbe7c871a5a6d7ed359100"; };

  };

}
#endif
