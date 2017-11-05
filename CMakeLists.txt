cmake_minimum_required(VERSION 3.8)
project(ARMour)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cc src/readers/stream_reader.h src/readers/file_reader.cpp src/readers/file_reader.h src/encoders/u_encoder.h src/encoders/arm_encoder.cpp src/encoders/arm_encoder.h src/encoders/arm.h)
add_executable(ARMour ${SOURCE_FILES})