cmake_minimum_required(VERSION 3.1)

project(RayTracer)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(Eigen3 REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

option(RT_BUILD_DOCS "Build docs" OFF)
if(RT_BUILD_DOCS)
	add_subdirectory(docs)
endif()

option(RT_BUILD_EXAMPLE "Build example" OFF)
if(RT_BUILD_EXAMPLE)
	add_subdirectory(example)
endif()

add_subdirectory(RayTracerLib)