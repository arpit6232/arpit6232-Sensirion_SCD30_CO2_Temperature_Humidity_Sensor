#ifndef _ROS_SERVICE_GetNeighbors_h
#define _ROS_SERVICE_GetNeighbors_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace marble_batman_network
{

static const char GETNEIGHBORS[] = "marble_batman_network/GetNeighbors";

  class GetNeighborsRequest : public ros::Msg
  {
    public:

    GetNeighborsRequest()
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

    const char * getType(){ return GETNEIGHBORS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetNeighborsResponse : public ros::Msg
  {
    public:
      typedef int32_t _num_neighbors_type;
      _num_neighbors_type num_neighbors;
      uint32_t neighbor_id_length;
      typedef char* _neighbor_id_type;
      _neighbor_id_type st_neighbor_id;
      _neighbor_id_type * neighbor_id;
      uint32_t last_seen_length;
      typedef char* _last_seen_type;
      _last_seen_type st_last_seen;
      _last_seen_type * last_seen;

    GetNeighborsResponse():
      num_neighbors(0),
      neighbor_id_length(0), neighbor_id(NULL),
      last_seen_length(0), last_seen(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_num_neighbors;
      u_num_neighbors.real = this->num_neighbors;
      *(outbuffer + offset + 0) = (u_num_neighbors.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_neighbors.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_neighbors.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_neighbors.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_neighbors);
      *(outbuffer + offset + 0) = (this->neighbor_id_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->neighbor_id_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->neighbor_id_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->neighbor_id_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighbor_id_length);
      for( uint32_t i = 0; i < neighbor_id_length; i++){
      uint32_t length_neighbor_idi = strlen(this->neighbor_id[i]);
      varToArr(outbuffer + offset, length_neighbor_idi);
      offset += 4;
      memcpy(outbuffer + offset, this->neighbor_id[i], length_neighbor_idi);
      offset += length_neighbor_idi;
      }
      *(outbuffer + offset + 0) = (this->last_seen_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->last_seen_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->last_seen_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->last_seen_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->last_seen_length);
      for( uint32_t i = 0; i < last_seen_length; i++){
      uint32_t length_last_seeni = strlen(this->last_seen[i]);
      varToArr(outbuffer + offset, length_last_seeni);
      offset += 4;
      memcpy(outbuffer + offset, this->last_seen[i], length_last_seeni);
      offset += length_last_seeni;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_num_neighbors;
      u_num_neighbors.base = 0;
      u_num_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_neighbors.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_neighbors = u_num_neighbors.real;
      offset += sizeof(this->num_neighbors);
      uint32_t neighbor_id_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      neighbor_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      neighbor_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      neighbor_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->neighbor_id_length);
      if(neighbor_id_lengthT > neighbor_id_length)
        this->neighbor_id = (char**)realloc(this->neighbor_id, neighbor_id_lengthT * sizeof(char*));
      neighbor_id_length = neighbor_id_lengthT;
      for( uint32_t i = 0; i < neighbor_id_length; i++){
      uint32_t length_st_neighbor_id;
      arrToVar(length_st_neighbor_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_neighbor_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_neighbor_id-1]=0;
      this->st_neighbor_id = (char *)(inbuffer + offset-1);
      offset += length_st_neighbor_id;
        memcpy( &(this->neighbor_id[i]), &(this->st_neighbor_id), sizeof(char*));
      }
      uint32_t last_seen_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      last_seen_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      last_seen_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      last_seen_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->last_seen_length);
      if(last_seen_lengthT > last_seen_length)
        this->last_seen = (char**)realloc(this->last_seen, last_seen_lengthT * sizeof(char*));
      last_seen_length = last_seen_lengthT;
      for( uint32_t i = 0; i < last_seen_length; i++){
      uint32_t length_st_last_seen;
      arrToVar(length_st_last_seen, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_last_seen; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_last_seen-1]=0;
      this->st_last_seen = (char *)(inbuffer + offset-1);
      offset += length_st_last_seen;
        memcpy( &(this->last_seen[i]), &(this->st_last_seen), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETNEIGHBORS; };
    const char * getMD5(){ return "e1b0a1063055c5226ee20e97371017d2"; };

  };

  class GetNeighbors {
    public:
    typedef GetNeighborsRequest Request;
    typedef GetNeighborsResponse Response;
  };

}
#endif
