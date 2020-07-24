cmake_minimum_required(VERSION 3.1)

project(RayTracerLib)

file(GLOB SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}/*.h
)

find_package(OpenMP)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include
)
if(OpenMP_CXX_FOUND)
	target_link_libraries(
		${PROJECT_NAME}
		PUBLIC
			OpenMP::OpenMP_CXX
	)
endif()