#ifndef _ROS_estop_msgs_EStopStatus_h
#define _ROS_estop_msgs_EStopStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace estop_msgs
{

  class EStopStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _sw_state_type;
      _sw_state_type sw_state;
      typedef uint8_t _radio_state_type;
      _radio_state_type radio_state;
      typedef const char* _led_color_type;
      _led_color_type led_color;

    EStopStatus():
      header(),
      sw_state(0),
      radio_state(0),
      led_color("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sw_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sw_state);
      *(outbuffer + offset + 0) = (this->radio_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->radio_state);
      uint32_t length_led_color = strlen(this->led_color);
      varToArr(outbuffer + offset, length_led_color);
      offset += 4;
      memcpy(outbuffer + offset, this->led_color, length_led_color);
      offset += length_led_color;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->sw_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sw_state);
      this->radio_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->radio_state);
      uint32_t length_led_color;
      arrToVar(length_led_color, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_led_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_led_color-1]=0;
      this->led_color = (char *)(inbuffer + offset-1);
      offset += length_led_color;
     return offset;
    }

    const char * getType(){ return "estop_msgs/EStopStatus"; };
    const char * getMD5(){ return "7c37e047e1b61742079abcceb5e955a0"; };

  };

}
#endif
