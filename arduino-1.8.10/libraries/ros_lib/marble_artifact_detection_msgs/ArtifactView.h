#ifndef _ROS_marble_artifact_detection_msgs_ArtifactView_h
#define _ROS_marble_artifact_detection_msgs_ArtifactView_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/CameraInfo.h"
#include "sensor_msgs/Image.h"

namespace marble_artifact_detection_msgs
{

  class ArtifactView : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _camera_type;
      _camera_type camera;
      typedef sensor_msgs::CameraInfo _camera_info_type;
      _camera_info_type camera_info;
      typedef sensor_msgs::Image _color_image_type;
      _color_image_type color_image;
      typedef sensor_msgs::Image _depth_image_type;
      _depth_image_type depth_image;

    ArtifactView():
      header(),
      camera(""),
      camera_info(),
      color_image(),
      depth_image()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_camera = strlen(this->camera);
      varToArr(outbuffer + offset, length_camera);
      offset += 4;
      memcpy(outbuffer + offset, this->camera, length_camera);
      offset += length_camera;
      offset += this->camera_info.serialize(outbuffer + offset);
      offset += this->color_image.serialize(outbuffer + offset);
      offset += this->depth_image.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_camera;
      arrToVar(length_camera, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_camera; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_camera-1]=0;
      this->camera = (char *)(inbuffer + offset-1);
      offset += length_camera;
      offset += this->camera_info.deserialize(inbuffer + offset);
      offset += this->color_image.deserialize(inbuffer + offset);
      offset += this->depth_image.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "marble_artifact_detection_msgs/ArtifactView"; };
    const char * getMD5(){ return "9bf16bcf96dd3d2aa8120f7d9a19e535"; };

  };

}
#endif
