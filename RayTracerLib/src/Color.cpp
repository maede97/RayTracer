#include "..\include\RayTracerLib\Color.h"

RayTracer::Color::Color()
{
}

RayTracer::Color::Color(double r, double g, double b) : r(r), g(g), b(b)
{
}

void RayTracer::Color::setRed(double r)
{
	this->r = r;
}

void RayTracer::Color::setGreen(double g)
{
	this->g = g;
}

void RayTracer::Color::setBlue(double b)
{
	this->b = b;
}


RayTracer::V3D RayTracer::Color::getColorVector() const
{
	return V3D(r, g, b);
}

double RayTracer::Color::getRed() const
{
	return r;
}

double RayTracer::Color::getGreen() const
{
	return g;
}

double RayTracer::Color::getBlue() const
{
	return b;
}


RayTracer::Color& RayTracer::Color::operator+(const Color& other)
{
	this->r += other.r;
	this->g += other.g;
	this->b += other.b;
	return *this;
}

RayTracer::Color& RayTracer::Color::operator*(const Color& other)
{
	this->r *= other.r;
	this->g *= other.g;
	this->b *= other.b;
	return *this;
}

RayTracer::Color& RayTracer::Color::operator*(const V3D& other)
{
	this->r *= other(0);
	this->g *= other(1);
	this->b *= other(2);
	return *this;
}

RayTracer::Color RayTracer::operator*(const Color& color, double factor)
{
	Color c;
	c.setRed(color.getRed() * factor);
	c.setGreen(color.getGreen() * factor);
	c.setBlue(color.getBlue() * factor);
	return c;
}
