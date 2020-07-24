#include "..\include\RayTracerLib\Shape.h"

RayTracer::Shape::Shape()
{
}

RayTracer::Shape::Shape(Color surfaceColor, Color emissionColor) : emissionColor(emissionColor), surfaceColor(surfaceColor)
{
}

RayTracer::Shape::Shape(double transparency, double reflection, Color surfaceColor, Color emissionColor) : transparency(transparency), reflection(reflection), emissionColor(emissionColor), surfaceColor(surfaceColor)
{
}

double RayTracer::Shape::getTransparency() const
{
	return transparency;
}

double RayTracer::Shape::getReflection() const
{
	return reflection;
}

RayTracer::Color RayTracer::Shape::getEmissionColor() const
{
	return emissionColor;
}

RayTracer::Color RayTracer::Shape::getSurfaceColor() const
{
	return surfaceColor;
}

RayTracer::Sphere::Sphere() : Shape()
{
}

RayTracer::Sphere::Sphere(V3D center, double r) : Shape(), center(center), radius(r)
{
}

RayTracer::Sphere::Sphere(V3D center, double radius, Color surfaceColor, Color emissionColor) : Shape(surfaceColor, emissionColor), center(center), radius(radius)
{
}

RayTracer::Sphere::Sphere(V3D center, double radius, double transparency, double reflection, Color surfaceColor, Color emissionColor) : Shape(transparency, reflection, surfaceColor, emissionColor), center(center), radius(radius)
{
}

bool RayTracer::Sphere::intersects(const Ray& ray, double& t0, double& t1, V3D& phit, V3D& nhit) const
{
	V3D l = center - ray.getOrigin();
	double tca = l.dot(ray.getDirection());
	if (tca < 0.0) return false;
	double d2 = l.dot(l) - tca * tca;
	if (d2 > radius * radius) return false;
	double thc = sqrt(radius * radius - d2);
	t0 = tca - thc;
	t1 = tca + thc;

	double tnear = INFINITY;
	if (t0 < 0) {
		t0 = t1;
	}
	if (t0 < tnear) {
		tnear = t0;
	}

	phit = ray.getOrigin() + ray.getDirection() * tnear;
	nhit = phit - center;
	nhit.normalize();
}

double RayTracer::Sphere::getRadius() const
{
	return radius;
}

RayTracer::V3D RayTracer::Sphere::getCenter() const
{
	return center;
}

RayTracer::Cube::Cube() : Shape()
{
}

RayTracer::Cube::Cube(V3D minCorner, V3D maxCorner) : Shape(), minCorner(minCorner), maxCorner(maxCorner)
{
}

RayTracer::Cube::Cube(V3D minCorner, V3D maxCorner, Color surfaceColor, Color emissionColor) : Shape(surfaceColor, emissionColor), minCorner(minCorner), maxCorner(maxCorner)
{
}

RayTracer::Cube::Cube(V3D minCorner, V3D maxCorner, double transparency, double reflection, Color surfaceColor, Color emissionColor) : Shape(transparency, reflection, surfaceColor, emissionColor), minCorner(minCorner), maxCorner(maxCorner)
{
}

bool RayTracer::Cube::intersects(const Ray& ray, double& t0, double& t1, V3D& phit, V3D& nhit) const
{
	double tx1 = (minCorner.x() - ray.getOrigin().x()) / ray.getDirection().x();
	double tx2 = (maxCorner.x() - ray.getOrigin().x()) / ray.getDirection().x();

	double tmin = std::min(tx1, tx2);
	double tmax = std::max(tx1, tx2);

	double ty1 = (minCorner.y() - ray.getOrigin().y()) / ray.getDirection().y();
	double ty2 = (maxCorner.y() - ray.getOrigin().y()) / ray.getDirection().y();

	tmin = std::max(tmin, std::min(ty1, ty2));
	tmax = std::min(tmax, std::max(ty1, ty2));

	double tz1 = (minCorner.z() - ray.getOrigin().z()) / ray.getDirection().z();
	double tz2 = (maxCorner.z() - ray.getOrigin().z()) / ray.getDirection().z();

	tmin = std::max(tmin, std::min(tz1, tz2));
	tmax = std::min(tmax, std::max(tz1, tz2));

	t0 = tmin;
	t1 = tmax;

	double t = tmax >= tmin ? tmin : -1.0;
	if (tmax < tmin) {
		return false;
	}

	phit = ray.getDirection() * t + ray.getOrigin();

	// compute normal
	double epsilon = 0.01;

	double cx = abs(phit.x() - minCorner.x());
	double fx = abs(phit.x() - maxCorner.x());
	double cy = abs(phit.y() - minCorner.y());
	double fy = abs(phit.y() - maxCorner.y());
	double cz = abs(phit.z() - minCorner.z());
	double fz = abs(phit.z() - maxCorner.z());

	if (cx < epsilon)
		nhit = V3D(-1.0, 0.0, 0.0);
	else if (fx < epsilon)
		nhit = V3D(1.0, 0.0, 0.0);
	else if (cy < epsilon)
		nhit = V3D(0.0, -1.0, 0.0);
	else if (fy < epsilon)
		nhit = V3D(0.0, 1.0, 0.0);
	else if (cz < epsilon)
		nhit = V3D(0.0, 0.0, -1.0);
	else if (fz < epsilon)
		nhit = V3D(0.0, 0.0, 1.0);
	nhit = V3D(0.0, 0.0, 0.0);

	return true;
}
