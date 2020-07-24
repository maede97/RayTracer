#pragma once

#include <RayTracerLib/Color.h>
#include <RayTracerLib/Math.h>
#include <RayTracerLib/Ray.h>

namespace RayTracer {
	class Shape {
	public:
		Shape();
		Shape(Color surfaceColor, Color emissionColor);
		Shape(double transparency, double reflection, Color surfaceColor, Color emissionColor);

		virtual bool intersects(const Ray& ray, double& t0, double& t1, V3D& phit, V3D& nhit) const = 0;

		double getTransparency() const;
		double getReflection() const;

		Color getEmissionColor() const;
		Color getSurfaceColor() const;

	private:
		Color emissionColor;
		Color surfaceColor;
		double transparency = 0.0;
		double reflection = 0.0;
	};

	class Sphere : public Shape {
	public:
		Sphere();
		Sphere(V3D center, double radius);
		Sphere(V3D center, double radius, Color surfaceColor, Color emissionColor);
		Sphere(V3D center, double radius, double transparency, double reflection, Color surfaceColor, Color emissionColor);

		bool intersects(const Ray& ray, double& t0, double& t1, V3D& phit, V3D& nhit) const override;

		double getRadius() const;
		V3D getCenter() const;

	private:
		V3D center;
		double radius = 0.0;
	};

	class Cube : public Shape {
	public:
		// TODO: Add orientation
		Cube();
		Cube(V3D minCorner, V3D maxCorner);
		Cube(V3D minCorner, V3D maxCorner, Color surfaceColor, Color emissionColor);
		Cube(V3D minCorner, V3D maxCorner, double transparency, double reflection, Color surfaceColor, Color emissionColor);

		bool intersects(const Ray& ray, double& t0, double& t1, V3D& phit, V3D& nhit) const override;
	private:
		V3D minCorner;
		V3D maxCorner;
	};
};