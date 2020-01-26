#ifndef _ROS_SERVICE_gettf_h
#define _ROS_SERVICE_gettf_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltf
{

static const char GETTF[] = "ltf/gettf";

  class gettfRequest : public ros::Msg
  {
    public:

    gettfRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETTF; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class gettfResponse : public ros::Msg
  {
    public:
      uint32_t ang_length;
      typedef float _ang_type;
      _ang_type st_ang;
      _ang_type * ang;
      uint32_t pos_length;
      typedef float _pos_type;
      _pos_type st_pos;
      _pos_type * pos;

    gettfResponse():
      ang_length(0), ang(NULL),
      pos_length(0), pos(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ang_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ang_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ang_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ang_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ang_length);
      for( uint32_t i = 0; i < ang_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->ang[i]);
      }
      *(outbuffer + offset + 0) = (this->pos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_length);
      for( uint32_t i = 0; i < pos_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->pos[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t ang_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ang_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ang_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ang_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ang_length);
      if(ang_lengthT > ang_length)
        this->ang = (float*)realloc(this->ang, ang_lengthT * sizeof(float));
      ang_length = ang_lengthT;
      for( uint32_t i = 0; i < ang_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_ang));
        memcpy( &(this->ang[i]), &(this->st_ang), sizeof(float));
      }
      uint32_t pos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pos_length);
      if(pos_lengthT > pos_length)
        this->pos = (float*)realloc(this->pos, pos_lengthT * sizeof(float));
      pos_length = pos_lengthT;
      for( uint32_t i = 0; i < pos_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_pos));
        memcpy( &(this->pos[i]), &(this->st_pos), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return GETTF; };
    const char * getMD5(){ return "dfdf9d528cf240d6724d744f5d6c0248"; };

  };

  class gettf {
    public:
    typedef gettfRequest Request;
    typedef gettfResponse Response;
  };

}
#endif
