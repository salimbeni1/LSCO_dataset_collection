cmake_minimum_required(VERSION 3.1.0)
project(ouster_ros)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  sensor_msgs
  geometry_msgs
  pcl_ros
  pcl_conversions
  roscpp
  ouster_client
  ouster_viz
  tf2
  tf2_ros
  tf2_geometry_msgs
)

add_message_files(FILES PacketMsg.msg)
add_service_files(FILES OS1ConfigSrv.srv)
generate_messages(DEPENDENCIES std_msgs sensor_msgs geometry_msgs)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ouster_ros
  CATKIN_DEPENDS
    roscpp message_runtime pcl_ros
    std_msgs sensor_msgs geometry_msgs
    ouster_client ouster_viz
)

add_library(ouster_ros src/os1_ros.cpp)
target_link_libraries(ouster_ros ${catkin_LIBRARIES})
add_dependencies(ouster_ros ${PROJECT_NAME}_gencpp)

add_executable(os1_node src/os1_node.cpp)
target_link_libraries(os1_node ouster_ros ${catkin_LIBRARIES})
add_dependencies(os1_node ${PROJECT_NAME}_gencpp)

add_executable(os1_cloud_node src/os1_cloud_node.cpp)
target_link_libraries(os1_cloud_node ouster_ros ${catkin_LIBRARIES})
add_dependencies(os1_cloud_node ${PROJECT_NAME}_gencpp)

add_executable(viz_node src/viz_node.cpp)
target_link_libraries(viz_node ${catkin_LIBRARIES})
add_dependencies(viz_node ${PROJECT_NAME}_gencpp)

add_executable(img_node src/img_node.cpp)
target_link_libraries(img_node ouster_ros ${catkin_LIBRARIES})
add_dependencies(img_node ${PROJECT_NAME}_gencpp)

install(TARGETS os1_node
                os1_cloud_node
                viz_node
                img_node
                ouster_ros
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(DIRECTORY launch
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
)
