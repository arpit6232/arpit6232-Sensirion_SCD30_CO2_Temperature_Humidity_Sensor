#ifndef _ROS_leica_ros_RadialMeasStamped_h
#define _ROS_leica_ros_RadialMeasStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace leica_ros
{

  class RadialMeasStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _radius_type;
      _radius_type radius;

    RadialMeasStamped():
      header(),
      radius(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->radius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius));
     return offset;
    }

    const char * getType(){ return "leica_ros/RadialMeasStamped"; };
    const char * getMD5(){ return "94cdf7a369324c8302bc36b708a633d5"; };

  };

}
#endif
