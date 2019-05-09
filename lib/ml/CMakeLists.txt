cmake_minimum_required(VERSION 3.7)
project(trafficLights)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_executable(trafficLights
  src/lights.grpc.pb.cc
  src/lights.pb.cc
  src/MJPEGWriter.cpp
  src/rpc.cpp
  src/image.cpp
  src/main.cpp
)

if ("${TARGET}" STREQUAL "RASPBERRY")
  include_directories(
    ${PATH}/include
    ${PATH}/include/opencv4
  )

  target_link_libraries(
    trafficLights
    ${PATH}/lib/libopencv_core.so
    ${PATH}/lib/libopencv_highgui.so
    ${PATH}/lib/libopencv_imgcodecs.so
    ${PATH}/lib/libopencv_imgproc.so
    ${PATH}/lib/libopencv_videoio.so

    ${PATH}/lib/libprotobuf.a

    ${PATH}/lib/libgrpc++.dylib
    ${PATH}/lib/libgrpc++_cronet.dylib
    ${PATH}/lib/libgrpc++_error_details.dylib
    ${PATH}/lib/libgrpc++_unsecure.dylib
    ${PATH}/lib/libgrpc++_reflection.dylib
    ${PATH}/lib/libgrpcpp_channelz.dylib
  )
else ()
  include_directories(
    /usr/local/include
    /usr/local/include/opencv4
  )

  target_link_libraries(
    trafficLights
    /usr/local/lib/libopencv_core.dylib
    /usr/local/lib/libopencv_highgui.dylib
    /usr/local/lib/libopencv_imgcodecs.dylib
    /usr/local/lib/libopencv_imgproc.dylib
    /usr/local/lib/libopencv_videoio.dylib

    /usr/local/lib/libprotobuf.a

    /usr/local/lib/libgrpc++.dylib
    /usr/local/lib/libgrpc++_cronet.dylib
    /usr/local/lib/libgrpc++_error_details.dylib
    /usr/local/lib/libgrpc++_unsecure.dylib
    /usr/local/lib/libgrpc++_reflection.dylib
    /usr/local/lib/libgrpcpp_channelz.dylib
  )
endif()