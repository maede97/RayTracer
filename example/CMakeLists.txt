cmake_minimum_required(VERSION 3.1)

project(RayTracerExamples)

set(TARGETS
	Spheres
)

foreach(T ${TARGETS})
	add_executable(${T} ${T}.cpp)
	
	target_link_libraries(${T} RayTracerLib)
	
	# Set Visual Studio folder
	set_property(TARGET ${T} PROPERTY FOLDER "Examples")
endforeach()