cmake_minimum_required(VERSION 2.8.3)
project(ouster_viz)

add_compile_options(-std=c++11)

find_package(Threads)
find_package(Eigen3 REQUIRED)
find_package(VTK REQUIRED COMPONENTS vtkCommonCore NO_MODULE)

set(VIZ_VTK_COMPONENTS vtkCommonCore vtkCommonDataModel vtkCommonMath
  vtkCommonTransforms vtkFiltersSources vtkImagingCore vtkInteractionStyle
  vtkRenderingCore
)
if(TARGET vtkRenderingOpenGL2)
  list(APPEND VIZ_VTK_COMPONENTS vtkRenderingOpenGL2)
else()
  list(APPEND VIZ_VTK_COMPONENTS vtkRenderingOpenGL)
endif()
find_package(VTK REQUIRED COMPONENTS ${VIZ_VTK_COMPONENTS} NO_MODULE)

include(${VTK_USE_FILE})

find_package(catkin REQUIRED COMPONENTS
  ouster_client
)

catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    ouster_viz
  DEPENDS
    VTK
  CATKIN_DEPENDS
    ouster_client
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
  ${VTK_INCLUDE_DIRS}
)

add_library(ouster_viz
  src/viz.cpp
)

add_dependencies(ouster_viz ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(ouster_viz
  ${catkin_LIBRARIES}
  ${VTK_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(viz
  src/main.cpp
  src/viz.cpp
)

target_link_libraries(viz
  ouster_viz
)

install(TARGETS ouster_viz viz
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE
)
