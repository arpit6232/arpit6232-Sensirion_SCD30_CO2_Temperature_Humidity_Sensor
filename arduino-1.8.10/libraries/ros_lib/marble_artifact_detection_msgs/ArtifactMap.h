#ifndef _ROS_marble_artifact_detection_msgs_ArtifactMap_h
#define _ROS_marble_artifact_detection_msgs_ArtifactMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "marble_artifact_detection_msgs/ArtifactArray.h"
#include "geometry_msgs/PoseStamped.h"

namespace marble_artifact_detection_msgs
{

  class ArtifactMap : public ros::Msg
  {
    public:
      typedef marble_artifact_detection_msgs::ArtifactArray _artifacts_type;
      _artifacts_type artifacts;
      uint32_t base_poses_length;
      typedef geometry_msgs::PoseStamped _base_poses_type;
      _base_poses_type st_base_poses;
      _base_poses_type * base_poses;
      uint32_t base_pose_indices_length;
      typedef uint32_t _base_pose_indices_type;
      _base_pose_indices_type st_base_pose_indices;
      _base_pose_indices_type * base_pose_indices;

    ArtifactMap():
      artifacts(),
      base_poses_length(0), base_poses(NULL),
      base_pose_indices_length(0), base_pose_indices(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->artifacts.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->base_poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->base_poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->base_poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->base_poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->base_poses_length);
      for( uint32_t i = 0; i < base_poses_length; i++){
      offset += this->base_poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->base_pose_indices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->base_pose_indices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->base_pose_indices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->base_pose_indices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->base_pose_indices_length);
      for( uint32_t i = 0; i < base_pose_indices_length; i++){
      *(outbuffer + offset + 0) = (this->base_pose_indices[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->base_pose_indices[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->base_pose_indices[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->base_pose_indices[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->base_pose_indices[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->artifacts.deserialize(inbuffer + offset);
      uint32_t base_poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      base_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      base_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      base_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->base_poses_length);
      if(base_poses_lengthT > base_poses_length)
        this->base_poses = (geometry_msgs::PoseStamped*)realloc(this->base_poses, base_poses_lengthT * sizeof(geometry_msgs::PoseStamped));
      base_poses_length = base_poses_lengthT;
      for( uint32_t i = 0; i < base_poses_length; i++){
      offset += this->st_base_poses.deserialize(inbuffer + offset);
        memcpy( &(this->base_poses[i]), &(this->st_base_poses), sizeof(geometry_msgs::PoseStamped));
      }
      uint32_t base_pose_indices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      base_pose_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      base_pose_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      base_pose_indices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->base_pose_indices_length);
      if(base_pose_indices_lengthT > base_pose_indices_length)
        this->base_pose_indices = (uint32_t*)realloc(this->base_pose_indices, base_pose_indices_lengthT * sizeof(uint32_t));
      base_pose_indices_length = base_pose_indices_lengthT;
      for( uint32_t i = 0; i < base_pose_indices_length; i++){
      this->st_base_pose_indices =  ((uint32_t) (*(inbuffer + offset)));
      this->st_base_pose_indices |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_base_pose_indices |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_base_pose_indices |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_base_pose_indices);
        memcpy( &(this->base_pose_indices[i]), &(this->st_base_pose_indices), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "marble_artifact_detection_msgs/ArtifactMap"; };
    const char * getMD5(){ return "9446723f1170b20a6bf319d6d884925d"; };

  };

}
#endif
