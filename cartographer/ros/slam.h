#ifndef CARTOGRAPHER_SLAM_H_
#define CARTOGRAPHER_SLAM_H_
#include "cartographer/Command.h"
#include "cartographer/io/submap_painter.h"
#include "cartographer/mapping/id.h"
#include "cartographer/mapping/map_builder.h"
#include "cartographer/mapping/proto/submap_visualization.pb.h"
#include "cartographer/transform/rigid_transform.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"
#include "nav_msgs/OccupancyGrid.h"
#include "nav_msgs/Path.h"
#include "ros/ros.h"
namespace cartographer {
namespace slam {

constexpr char kMapsDirectory[] = "/root/gamma/maps/";
class Slam {
 public:
  explicit Slam();
  ~Slam();
  Slam(const Slam&) = delete;
  Slam& operator=(const Slam&) = delete;
  bool SetCommandCallBack(Command::Request& req, Command::Response& res);
  void PublishNodes();
  void PublishSubmaps();

 private:
  std::unique_ptr<mapping::MapBuilder> map_builder_ptr_;
  std::unique_ptr<ros::NodeHandle> node_handle_ptr_;
  ros::ServiceServer command_srv_;
  ros::Publisher submaps_publisher_;
  ros::Publisher submap_poses_publisher_;
  ros::Publisher node_poses_publisher_;
};
}  // namespace slam
}  // namespace cartographer
#endif