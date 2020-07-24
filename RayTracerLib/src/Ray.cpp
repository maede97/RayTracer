#include <RayTracerLib/Ray.h>

RayTracer::Ray::Ray()
{
}

RayTracer::Ray::Ray(V3D origin, V3D direction) : origin(origin), direction(direction)
{
	direction.normalize();
}

RayTracer::V3D RayTracer::Ray::getOrigin() const
{
	return origin;
}

RayTracer::V3D RayTracer::Ray::getDirection() const
{
	return direction;
}
