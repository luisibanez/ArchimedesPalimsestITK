cmake_minimum_required(VERSION 2.8)
if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND CMAKE_POLICY)

project(ArchimedesPalimsestITK)


set(LIBRARY_OUTPUT_PATH    ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake ${CMAKE_MODULE_PATH})

include(CTest)
include(ArchimedesPalimsestITKExternalData)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_subdirectory(Source)
add_subdirectory(Testing)
