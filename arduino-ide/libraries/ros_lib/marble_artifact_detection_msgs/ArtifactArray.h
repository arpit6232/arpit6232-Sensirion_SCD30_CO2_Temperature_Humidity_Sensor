#ifndef _ROS_marble_artifact_detection_msgs_ArtifactArray_h
#define _ROS_marble_artifact_detection_msgs_ArtifactArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "marble_artifact_detection_msgs/Artifact.h"
#include "geometry_msgs/PoseStamped.h"

namespace marble_artifact_detection_msgs
{

  class ArtifactArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _owner_type;
      _owner_type owner;
      uint32_t artifacts_length;
      typedef marble_artifact_detection_msgs::Artifact _artifacts_type;
      _artifacts_type st_artifacts;
      _artifacts_type * artifacts;
      uint32_t base_poses_length;
      typedef geometry_msgs::PoseStamped _base_poses_type;
      _base_poses_type st_base_poses;
      _base_poses_type * base_poses;
      uint32_t base_pose_indices_length;
      typedef uint32_t _base_pose_indices_type;
      _base_pose_indices_type st_base_pose_indices;
      _base_pose_indices_type * base_pose_indices;
      typedef uint8_t _num_artifacts_type;
      _num_artifacts_type num_artifacts;

    ArtifactArray():
      header(),
      owner(""),
      artifacts_length(0), artifacts(NULL),
      base_poses_length(0), base_poses(NULL),
      base_pose_indices_length(0), base_pose_indices(NULL),
      num_artifacts(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_owner = strlen(this->owner);
      varToArr(outbuffer + offset, length_owner);
      offset += 4;
      memcpy(outbuffer + offset, this->owner, length_owner);
      offset += length_owner;
      *(outbuffer + offset + 0) = (this->artifacts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->artifacts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->artifacts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->artifacts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->artifacts_length);
      for( uint32_t i = 0; i < artifacts_length; i++){
      offset += this->artifacts[i].serialize(outbuffer + offset);
      }
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
      *(outbuffer + offset + 0) = (this->num_artifacts >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num_artifacts);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_owner;
      arrToVar(length_owner, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_owner; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_owner-1]=0;
      this->owner = (char *)(inbuffer + offset-1);
      offset += length_owner;
      uint32_t artifacts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      artifacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      artifacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      artifacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->artifacts_length);
      if(artifacts_lengthT > artifacts_length)
        this->artifacts = (marble_artifact_detection_msgs::Artifact*)realloc(this->artifacts, artifacts_lengthT * sizeof(marble_artifact_detection_msgs::Artifact));
      artifacts_length = artifacts_lengthT;
      for( uint32_t i = 0; i < artifacts_length; i++){
      offset += this->st_artifacts.deserialize(inbuffer + offset);
        memcpy( &(this->artifacts[i]), &(this->st_artifacts), sizeof(marble_artifact_detection_msgs::Artifact));
      }
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
      this->num_artifacts =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->num_artifacts);
     return offset;
    }

    const char * getType(){ return "marble_artifact_detection_msgs/ArtifactArray"; };
    const char * getMD5(){ return "445a770a66bf303753034a733ed68ca3"; };

  };

}
#endif
