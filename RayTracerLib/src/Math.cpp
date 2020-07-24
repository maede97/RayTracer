#include <RayTracerLib/Math.h>
#include <cmath>

double RayTracer::fdiv(double a, double b) {
	if (b == 0)
	{
		if (a == 0) return 0;
		else return LARGE_VAL * RayTracer::signum(a);
	}
	else
	{
		if (a == 0) return 0;
		else
		{
			if ((a + b) == a) return LARGE_VAL * RayTracer::signum(a) * RayTracer::signum(b);
			else return a / b;
		}
	}
}

int RayTracer::signum(double x) {
	return (x == 0 ? 0 : (x < 0 ? -1 : 1));
}

double RayTracer::mix(double a, double b, double mix)
{
	return (1.0 - mix) * a + mix * b;
}
