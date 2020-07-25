#include <RayTracerLib/Math.h>
#include <cmath>

int RayTracer::signum(double x) {
	return (x == 0 ? 0 : (x < 0 ? -1 : 1));
}

double RayTracer::mix(double a, double b, double mix)
{
	return (1.0 - mix) * a + mix * b;
}
