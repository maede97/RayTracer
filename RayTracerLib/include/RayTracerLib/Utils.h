#pragma once

/** @file Utils.h
 * @brief Contains helper functions
 */

#include <RayTracerLib/Ray.h>
#include <RayTracerLib/Shape.h>
#include <RayTracerLib/Math.h>

#include <vector>

namespace RayTracer {
	/**
	 * @brief Class to hold utils
	 */
	class Utils {
	public:
		/**
		 * @brief Traces a ray with given shapes and depth
		 * @param ray The ray to trace
		 * @param shapes The vector of shapes
		 * @param depth The current depth of the ray
		 * @param MAX_RAY_DEPTH The maximum depth of the ray
		 * @return The color at that given point
		 */
		static Color trace(const Ray& ray, const std::vector<Shape*>& shapes, const int& depth, const int MAX_RAY_DEPTH);

		/**
		 * @brief Renders shapes with given image size and filename
		 * @param shapes The vector of shapes
		 * @param width The width of the image
		 * @param height The height of the image
		 * @param MAX_RAY_DEPTH The maximum ray depth
		 * @param filename The filename of the image to save
		 */
		static void render(const std::vector<Shape*>& shapes, unsigned width = 1920, unsigned height = 1080, const int MAX_RAY_DEPTH = 5, const char* filename = "untitled.ppm");
	};
};