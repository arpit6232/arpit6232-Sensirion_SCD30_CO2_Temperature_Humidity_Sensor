#ifndef _ROS_SERVICE_TraceRoute_h
#define _ROS_SERVICE_TraceRoute_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marble_batman_network
{

static const char TRACEROUTE[] = "marble_batman_network/TraceRoute";

  class TraceRouteRequest : public ros::Msg
  {
    public:
      typedef const char* _location_type;
      _location_type location;

    TraceRouteRequest():
      location("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_location = strlen(this->location);
      varToArr(outbuffer + offset, length_location);
      offset += 4;
      memcpy(outbuffer + offset, this->location, length_location);
      offset += length_location;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_location;
      arrToVar(length_location, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_location; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_location-1]=0;
      this->location = (char *)(inbuffer + offset-1);
      offset += length_location;
     return offset;
    }

    const char * getType(){ return TRACEROUTE; };
    const char * getMD5(){ return "03da474bc61cfeb81a8854b4ca05bafa"; };

  };

  class TraceRouteResponse : public ros::Msg
  {
    public:
      uint32_t routeList_length;
      typedef char* _routeList_type;
      _routeList_type st_routeList;
      _routeList_type * routeList;
      typedef const char* _msg_type;
      _msg_type msg;

    TraceRouteResponse():
      routeList_length(0), routeList(NULL),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->routeList_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->routeList_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->routeList_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->routeList_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->routeList_length);
      for( uint32_t i = 0; i < routeList_length; i++){
      uint32_t length_routeListi = strlen(this->routeList[i]);
      varToArr(outbuffer + offset, length_routeListi);
      offset += 4;
      memcpy(outbuffer + offset, this->routeList[i], length_routeListi);
      offset += length_routeListi;
      }
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t routeList_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      routeList_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      routeList_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      routeList_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->routeList_length);
      if(routeList_lengthT > routeList_length)
        this->routeList = (char**)realloc(this->routeList, routeList_lengthT * sizeof(char*));
      routeList_length = routeList_lengthT;
      for( uint32_t i = 0; i < routeList_length; i++){
      uint32_t length_st_routeList;
      arrToVar(length_st_routeList, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_routeList; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_routeList-1]=0;
      this->st_routeList = (char *)(inbuffer + offset-1);
      offset += length_st_routeList;
        memcpy( &(this->routeList[i]), &(this->st_routeList), sizeof(char*));
      }
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return TRACEROUTE; };
    const char * getMD5(){ return "13a4afeaeebc4237ad6ef26aa5898701"; };

  };

  class TraceRoute {
    public:
    typedef TraceRouteRequest Request;
    typedef TraceRouteResponse Response;
  };

}
#endif
