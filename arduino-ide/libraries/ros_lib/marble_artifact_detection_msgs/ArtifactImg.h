#ifndef _ROS_marble_artifact_detection_msgs_ArtifactImg_h
#define _ROS_marble_artifact_detection_msgs_ArtifactImg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/CompressedImage.h"

namespace marble_artifact_detection_msgs
{

  class ArtifactImg : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sensor_msgs::CompressedImage _artifact_img_type;
      _artifact_img_type artifact_img;
      typedef int32_t _image_id_type;
      _image_id_type image_id;
      typedef float _obj_prob_type;
      _obj_prob_type obj_prob;
      typedef const char* _vehicle_reporter_type;
      _vehicle_reporter_type vehicle_reporter;

    ArtifactImg():
      header(),
      artifact_img(),
      image_id(0),
      obj_prob(0),
      vehicle_reporter("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->artifact_img.serialize(outbuffer + offset);
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
      offset += this->artifact_img.deserialize(inbuffer + offset);
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

    const char * getType(){ return "marble_artifact_detection_msgs/ArtifactImg"; };
    const char * getMD5(){ return "1355af180ce242c4dae3e687961ea6e7"; };

  };

}
#endif
