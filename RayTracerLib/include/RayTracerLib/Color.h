#pragma once
#include <RayTracerLib/Math.h>

namespace RayTracer {
	class Color {
	public:
		Color();
		Color(double r, double g, double b);


		void setRed(double r);
		void setGreen(double g);
		void setBlue(double b);

		V3D getColorVector() const;

		double getRed() const;
		double getGreen() const;
		double getBlue() const;

		Color& operator+(const Color& other);
		Color& operator*(const Color& other);
		Color& operator*(const V3D& other);

	private:
		double r = 0.0;
		double g = 0.0;
		double b = 0.0;
	};

	Color operator*(const Color& color, double factor);
};