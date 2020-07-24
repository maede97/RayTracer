#pragma once

#include <RayTracerLib/Ray.h>
#include <RayTracerLib/Shape.h>
#include <RayTracerLib/Math.h>

#include <vector>

namespace RayTracer {

	/**
	 * @brief Traces a ray with given shapes and depth
	 * @param ray The ray to trace
	 * @param shapes The vector of shapes
	 * @param depth The current depth of the ray
	 * @param MAX_RAY_DEPTH The maximum depth of the ray
	 * @param return The color at that given point
	*/
	Color trace(const Ray& ray, const std::vector<Shape*>& shapes, const int& depth, const int MAX_RAY_DEPTH);

	void render(const std::vector<Shape*>& shapes, unsigned width = 1920, unsigned heigth = 1080, const int MAX_RAY_DEPTH = 5, const char* filename = "untitled.ppm");

};