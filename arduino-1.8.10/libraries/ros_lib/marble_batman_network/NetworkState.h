#ifndef _ROS_marble_batman_network_NetworkState_h
#define _ROS_marble_batman_network_NetworkState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace marble_batman_network
{

  class NetworkState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _signal_strength_type;
      _signal_strength_type signal_strength;
      typedef int32_t _noise_type;
      _noise_type noise;
      typedef const char* _link_quality_type;
      _link_quality_type link_quality;

    NetworkState():
      header(),
      signal_strength(0),
      noise(0),
      link_quality("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_signal_strength;
      u_signal_strength.real = this->signal_strength;
      *(outbuffer + offset + 0) = (u_signal_strength.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_signal_strength.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_signal_strength.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_signal_strength.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signal_strength);
      union {
        int32_t real;
        uint32_t base;
      } u_noise;
      u_noise.real = this->noise;
      *(outbuffer + offset + 0) = (u_noise.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_noise.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_noise.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_noise.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->noise);
      uint32_t length_link_quality = strlen(this->link_quality);
      varToArr(outbuffer + offset, length_link_quality);
      offset += 4;
      memcpy(outbuffer + offset, this->link_quality, length_link_quality);
      offset += length_link_quality;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_signal_strength;
      u_signal_strength.base = 0;
      u_signal_strength.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_signal_strength.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_signal_strength.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_signal_strength.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->signal_strength = u_signal_strength.real;
      offset += sizeof(this->signal_strength);
      union {
        int32_t real;
        uint32_t base;
      } u_noise;
      u_noise.base = 0;
      u_noise.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_noise.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_noise.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_noise.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->noise = u_noise.real;
      offset += sizeof(this->noise);
      uint32_t length_link_quality;
      arrToVar(length_link_quality, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_quality; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_quality-1]=0;
      this->link_quality = (char *)(inbuffer + offset-1);
      offset += length_link_quality;
     return offset;
    }

    const char * getType(){ return "marble_batman_network/NetworkState"; };
    const char * getMD5(){ return "ba051c7e1cdb1d4b00df5cde30399041"; };

  };

}
#endif
