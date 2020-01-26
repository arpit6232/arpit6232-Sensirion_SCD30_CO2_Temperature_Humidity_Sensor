#ifndef _ROS_marble_artifact_detection_msgs_Artifact_h
#define _ROS_marble_artifact_detection_msgs_Artifact_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace marble_artifact_detection_msgs
{

  class Artifact : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef const char* _obj_class_type;
      _obj_class_type obj_class;
      typedef float _obj_prob_type;
      _obj_prob_type obj_prob;
      typedef bool _has_been_reported_type;
      _has_been_reported_type has_been_reported;
      typedef int32_t _image_id_type;
      _image_id_type image_id;
      typedef const char* _vehicle_reporter_type;
      _vehicle_reporter_type vehicle_reporter;

    Artifact():
      header(),
      position(),
      obj_class(""),
      obj_prob(0),
      has_been_reported(0),
      image_id(0),
      vehicle_reporter("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      uint32_t length_obj_class = strlen(this->obj_class);
      varToArr(outbuffer + offset, length_obj_class);
      offset += 4;
      memcpy(outbuffer + offset, this->obj_class, length_obj_class);
      offset += length_obj_class;
      union {
        float real;
        uint32_t base;
      } u_obj_prob;
      u_obj_prob.real = this->obj_prob;
      *(outbuffer + offset + 0) = (u_obj_prob.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obj_prob.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obj_prob.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obj_prob.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obj_prob);
      union {
        bool real;
        uint8_t base;
      } u_has_been_reported;
      u_has_been_reported.real = this->has_been_reported;
      *(outbuffer + offset + 0) = (u_has_been_reported.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_been_reported);
      union {
        int32_t real;
        uint32_t base;
      } u_image_id;
      u_image_id.real = this->image_id;
      *(outbuffer + offset + 0) = (u_image_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_id);
      uint32_t length_vehicle_reporter = strlen(this->vehicle_reporter);
      varToArr(outbuffer + offset, length_vehicle_reporter);
      offset += 4;
      memcpy(outbuffer + offset, this->vehicle_reporter, length_vehicle_reporter);
      offset += length_vehicle_reporter;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      uint32_t length_obj_class;
      arrToVar(length_obj_class, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_obj_class; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_obj_class-1]=0;
      this->obj_class = (char *)(inbuffer + offset-1);
      offset += length_obj_class;
      union {
        float real;
        uint32_t base;
      } u_obj_prob;
      u_obj_prob.base = 0;
      u_obj_prob.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obj_prob.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obj_prob.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obj_prob.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obj_prob = u_obj_prob.real;
      offset += sizeof(this->obj_prob);
      union {
        bool real;
        uint8_t base;
      } u_has_been_reported;
      u_has_been_reported.base = 0;
      u_has_been_reported.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_been_reported = u_has_been_reported.real;
      offset += sizeof(this->has_been_reported);
      union {
        int32_t real;
        uint32_t base;
      } u_image_id;
      u_image_id.base = 0;
      u_image_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->image_id = u_image_id.real;
      offset += sizeof(this->image_id);
      uint32_t length_vehicle_reporter;
      arrToVar(length_vehicle_reporter, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_vehicle_reporter; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_vehicle_reporter-1]=0;
      this->vehicle_reporter = (char *)(inbuffer + offset-1);
      offset += length_vehicle_reporter;
     return offset;
    }

    const char * getType(){ return "marble_artifact_detection_msgs/Artifact"; };
    const char * getMD5(){ return "6d2c1eb7e6eb512a7b8e4d88506d8f10"; };

  };

}
#endif
