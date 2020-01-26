#ifndef _ROS_SERVICE_CommNodeReachable_h
#define _ROS_SERVICE_CommNodeReachable_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marble_batman_network
{

static const char COMMNODEREACHABLE[] = "marble_batman_network/CommNodeReachable";

  class CommNodeReachableRequest : public ros::Msg
  {
    public:
      typedef const char* _dest_ip_addr_type;
      _dest_ip_addr_type dest_ip_addr;

    CommNodeReachableRequest():
      dest_ip_addr("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_dest_ip_addr = strlen(this->dest_ip_addr);
      varToArr(outbuffer + offset, length_dest_ip_addr);
      offset += 4;
      memcpy(outbuffer + offset, this->dest_ip_addr, length_dest_ip_addr);
      offset += length_dest_ip_addr;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_dest_ip_addr;
      arrToVar(length_dest_ip_addr, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dest_ip_addr; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dest_ip_addr-1]=0;
      this->dest_ip_addr = (char *)(inbuffer + offset-1);
      offset += length_dest_ip_addr;
     return offset;
    }

    const char * getType(){ return COMMNODEREACHABLE; };
    const char * getMD5(){ return "ae21fc1baf35aa9161908a285de8b393"; };

  };

  class CommNodeReachableResponse : public ros::Msg
  {
    public:
      typedef float _packet_loss_type;
      _packet_loss_type packet_loss;
      typedef float _avg_time_type;
      _avg_time_type avg_time;

    CommNodeReachableResponse():
      packet_loss(0),
      avg_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_packet_loss;
      u_packet_loss.real = this->packet_loss;
      *(outbuffer + offset + 0) = (u_packet_loss.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_packet_loss.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_packet_loss.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_packet_loss.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->packet_loss);
      union {
        float real;
        uint32_t base;
      } u_avg_time;
      u_avg_time.real = this->avg_time;
      *(outbuffer + offset + 0) = (u_avg_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_avg_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_avg_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_avg_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->avg_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_packet_loss;
      u_packet_loss.base = 0;
      u_packet_loss.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_packet_loss.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_packet_loss.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_packet_loss.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->packet_loss = u_packet_loss.real;
      offset += sizeof(this->packet_loss);
      union {
        float real;
        uint32_t base;
      } u_avg_time;
      u_avg_time.base = 0;
      u_avg_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_avg_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_avg_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_avg_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->avg_time = u_avg_time.real;
      offset += sizeof(this->avg_time);
     return offset;
    }

    const char * getType(){ return COMMNODEREACHABLE; };
    const char * getMD5(){ return "af41954bbec9e5340d8dc5c25fbd0b1e"; };

  };

  class CommNodeReachable {
    public:
    typedef CommNodeReachableRequest Request;
    typedef CommNodeReachableResponse Response;
  };

}
#endif
