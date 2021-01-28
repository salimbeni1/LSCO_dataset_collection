cmake_minimum_required(VERSION 2.8.3)
project(ouster_client)

add_compile_options(-std=c++11)

find_package(jsoncpp REQUIRED)

find_package(catkin REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ouster_client
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_library(ouster_client
  src/os1.cpp
  src/os1_util.cpp)

add_dependencies(ouster_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ouster_client jsoncpp ${catkin_LIBRARIES})

add_executable(ouster_client_example src/main.cpp)

target_link_libraries(ouster_client_example ouster_client)

install(TARGETS ouster_client_example ouster_client
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
)
