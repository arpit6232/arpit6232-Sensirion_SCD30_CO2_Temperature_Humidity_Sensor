#ifndef _ROS_leica_ros_AngleMeasStamped_h
#define _ROS_leica_ros_AngleMeasStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace leica_ros
{

  class AngleMeasStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _theta_type;
      _theta_type theta;
      typedef float _phi_type;
      _phi_type phi;

    AngleMeasStamped():
      header(),
      theta(0),
      phi(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->theta);
      offset += serializeAvrFloat64(outbuffer + offset, this->phi);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->phi));
     return offset;
    }

    const char * getType(){ return "leica_ros/AngleMeasStamped"; };
    const char * getMD5(){ return "d5b6306d616b12d92ce706280607d735"; };

  };

}
#endif
