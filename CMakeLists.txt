cmake_minimum_required(VERSION 3.8)
project(ARMour)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cc src/readers/stream_reader.h src/readers/file_reader.cc src/readers/file_reader.h src/encoders/u_encoder.h src/encoders/arm_encoder.cc src/encoders/arm_encoder.h src/encoders/arm.h src/readers/memory_reader.cc src/readers/memory_reader.h src/encoders/arm.cc)
add_executable(ARMour ${SOURCE_FILES})