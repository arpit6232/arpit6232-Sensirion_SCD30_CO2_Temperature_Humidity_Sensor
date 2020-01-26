#ifndef _ROS_ltf_InstrumentState_h
#define _ROS_ltf_InstrumentState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ltf
{

  class InstrumentState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _lock_status_type;
      _lock_status_type lock_status;
      typedef int8_t _battery_pct_type;
      _battery_pct_type battery_pct;
      typedef const char* _power_source_type;
      _power_source_type power_source;
      typedef bool _laser_type;
      _laser_type laser;

    InstrumentState():
      header(),
      lock_status(""),
      battery_pct(0),
      power_source(""),
      laser(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_lock_status = strlen(this->lock_status);
      varToArr(outbuffer + offset, length_lock_status);
      offset += 4;
      memcpy(outbuffer + offset, this->lock_status, length_lock_status);
      offset += length_lock_status;
      union {
        int8_t real;
        uint8_t base;
      } u_battery_pct;
      u_battery_pct.real = this->battery_pct;
      *(outbuffer + offset + 0) = (u_battery_pct.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_pct);
      uint32_t length_power_source = strlen(this->power_source);
      varToArr(outbuffer + offset, length_power_source);
      offset += 4;
      memcpy(outbuffer + offset, this->power_source, length_power_source);
      offset += length_power_source;
      union {
        bool real;
        uint8_t base;
      } u_laser;
      u_laser.real = this->laser;
      *(outbuffer + offset + 0) = (u_laser.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->laser);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_lock_status;
      arrToVar(length_lock_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lock_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lock_status-1]=0;
      this->lock_status = (char *)(inbuffer + offset-1);
      offset += length_lock_status;
      union {
        int8_t real;
        uint8_t base;
      } u_battery_pct;
      u_battery_pct.base = 0;
      u_battery_pct.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->battery_pct = u_battery_pct.real;
      offset += sizeof(this->battery_pct);
      uint32_t length_power_source;
      arrToVar(length_power_source, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_power_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_power_source-1]=0;
      this->power_source = (char *)(inbuffer + offset-1);
      offset += length_power_source;
      union {
        bool real;
        uint8_t base;
      } u_laser;
      u_laser.base = 0;
      u_laser.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->laser = u_laser.real;
      offset += sizeof(this->laser);
     return offset;
    }

    const char * getType(){ return "ltf/InstrumentState"; };
    const char * getMD5(){ return "c80ed2c351ab3f857964fc3a340414d2"; };

  };

}
#endif
