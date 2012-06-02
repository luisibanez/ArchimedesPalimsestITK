cmake_minimum_required(VERSION 2.8)
if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND CMAKE_POLICY)

project(ArchimedesPalimsestITK)

set(EXECUTABLE_OUTPUT_PATH ${ArchimedesPalimsestITK_BINARY_DIR}/bin)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_subdirectory(Source)
add_subdirectory(Testing)
