#ifndef _ROS_marble_batman_network_ArtifactNetwork_h
#define _ROS_marble_batman_network_ArtifactNetwork_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace marble_batman_network
{

  class ArtifactNetwork : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _network_name_type;
      _network_name_type network_name;
      typedef int32_t _signal_level_type;
      _signal_level_type signal_level;
      typedef float _qos_type;
      _qos_type qos;
      typedef bool _detected_type;
      _detected_type detected;

    ArtifactNetwork():
      header(),
      network_name(""),
      signal_level(0),
      qos(0),
      detected(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_network_name = strlen(this->network_name);
      varToArr(outbuffer + offset, length_network_name);
      offset += 4;
      memcpy(outbuffer + offset, this->network_name, length_network_name);
      offset += length_network_name;
      union {
        int32_t real;
        uint32_t base;
      } u_signal_level;
      u_signal_level.real = this->signal_level;
      *(outbuffer + offset + 0) = (u_signal_level.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_signal_level.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_signal_level.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_signal_level.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signal_level);
      union {
        float real;
        uint32_t base;
      } u_qos;
      u_qos.real = this->qos;
      *(outbuffer + offset + 0) = (u_qos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_qos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_qos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_qos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->qos);
      union {
        bool real;
        uint8_t base;
      } u_detected;
      u_detected.real = this->detected;
      *(outbuffer + offset + 0) = (u_detected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detected);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_network_name;
      arrToVar(length_network_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_network_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_network_name-1]=0;
      this->network_name = (char *)(inbuffer + offset-1);
      offset += length_network_name;
      union {
        int32_t real;
        uint32_t base;
      } u_signal_level;
      u_signal_level.base = 0;
      u_signal_level.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_signal_level.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_signal_level.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_signal_level.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->signal_level = u_signal_level.real;
      offset += sizeof(this->signal_level);
      union {
        float real;
        uint32_t base;
      } u_qos;
      u_qos.base = 0;
      u_qos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_qos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_qos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_qos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->qos = u_qos.real;
      offset += sizeof(this->qos);
      union {
        bool real;
        uint8_t base;
      } u_detected;
      u_detected.base = 0;
      u_detected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detected = u_detected.real;
      offset += sizeof(this->detected);
     return offset;
    }

    const char * getType(){ return "marble_batman_network/ArtifactNetwork"; };
    const char * getMD5(){ return "f2da8132924ae54a153f6f43fa2b0edd"; };

  };

}
#endif
