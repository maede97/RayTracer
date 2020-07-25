#pragma once

#include <RayTracerLib/Color.h>
#include <RayTracerLib/Math.h>
#include <RayTracerLib/Ray.h>

namespace RayTracer {
	/**
	 * @brief Abstract Base class for the renderer
	 */
	class Shape {
	public:
		/**
		 * @brief Default constructor, set transparency and reflection to 0 and Color to default
		 */
		Shape();

		/**
		 * @brief Constructor using two colors
		 * @param surfaceColor The color of the surface of the shape
		 * @param emissionColor THe color of the emission
		 */
		Shape(Color surfaceColor, Color emissionColor);

		/**
		 * @brief Constructor using all members
		 * @param transparency The transparency of this shape
		 * @param reflection The reflection of this shape
		 * @param surfaceColor The color of the surface of the shape
		 * @param emissionColor The color of the emission
		 */
		Shape(double transparency, double reflection, Color surfaceColor, Color emissionColor);

		/**
		 * @brief Checks if a ray intersects with this shape, to be overloaded
		 * @param ray The ray to check
		 * @param t0 The point on the ray where the ray enters (only valid if return value true)
		 * @param t1 The point on the ray where the ray leaves (only valid if return value true)
		 * @param phit The point where the ray hit
		 * @param nhit The normal at the point where the ray hit
		 * @return Whether the ray hit or not
		 */
		virtual bool intersects(const Ray& ray, double& t0, double& t1, V3D& phit, V3D& nhit) const = 0;

		/**
		 * @brief Get the transparency of the shape
		 * @return The transparency value
		 */
		double getTransparency() const;

		/**
		 * @brief Get the reflection of the shape
		 * @return The reflection value
		 */
		double getReflection() const;

		/**
		 * @brief Get the emission color of the shape
		 * @return The emission color
		 */
		Color getEmissionColor() const;

		/**
		 * @brief Get the surface color of the shape
		 * @return The surface color value
		 */
		Color getSurfaceColor() const;

	private:
		Color emissionColor; ///< the emission color
		Color surfaceColor; ///< the surface color
		double transparency = 0.0; ///< the transparency
		double reflection = 0.0; /// < the reflection
	};

	/**
	 * @brief Class to hold a special Shape, a Sphere
	 */
	class Sphere : public Shape {
	public:
		/**
		 * @brief Default constructor, see Shape::Shape()
		 */
		Sphere();

		/**
		 * @brief Constructs a Sphere from center and radius, see Shape::Shape()
		 * @param center The center of the sphere
		 * @param radius The radius of the sphere
		 */
		Sphere(V3D center, double radius);

		/**
		 * @brief Constructs a Sphere from center, radius and colors
		 * @param center The center of the sphere
		 * @param radius The radius of the sphere
		 * @copydetails Shape::Shape(Color surfaceColor, Color emissionColor)
		 */
		Sphere(V3D center, double radius, Color surfaceColor, Color emissionColor);

		/**
		 * @brief Constructs a Sphere from all members
		 * @param center The center of the sphere
		 * @param radius The radius of the sphere
		 * @copydetails Shape::Shape(double transparency, double reflection, Color surfaceColor, Color emissionColor)
		 */
		Sphere(V3D center, double radius, double transparency, double reflection, Color surfaceColor, Color emissionColor);

		bool intersects(const Ray& ray, double& t0, double& t1, V3D& phit, V3D& nhit) const override;

		/**
		 * @brief Returns the radius of the sphere
		 * @return The radius
		 */
		double getRadius() const;

		/**
		 * @brief Returns the center of the sphere
		 * @return The center
		 */
		V3D getCenter() const;

	private:
		V3D center; ///< center of the sphere
		double radius = 0.0; ///< radius of the sphere
	};

	/**
	 * @brief Class to hold a special Shape, a Cube
	 */
	class Cube : public Shape {
	public:
		// TODO: Add orientation

		/**
		 * @brief Default constructor, see Shape::Shape()
		 */
		Cube();

		/**
		 * @brief Constructs a cube from two given corners
		 * @param minCorner the first corner
		 * @param maxCorner the second corner
		 */
		Cube(V3D minCorner, V3D maxCorner);

		/**
		 * @brief Constructs a cube from two given corners and colors
		 * @param minCorner the first corner
		 * @param maxCorner the second corner
		 * @copydetails Shape::Shape(Color surfaceColor, Color emissionColor)
		 */
		Cube(V3D minCorner, V3D maxCorner, Color surfaceColor, Color emissionColor);

		/**
		 * @brief Constructs a cube from all members
		 * @param minCorner the first corner
		 * @param maxCorner the second corner
		 * @copydetails Shape::Shape(double transparency, double reflection, Color surfaceColor, Color emissionColor)
		 */
		Cube(V3D minCorner, V3D maxCorner, double transparency, double reflection, Color surfaceColor, Color emissionColor);

		bool intersects(const Ray& ray, double& t0, double& t1, V3D& phit, V3D& nhit) const override;
	private:
		V3D minCorner; ///< the first corner
		V3D maxCorner; ///< the second corner
	};
};