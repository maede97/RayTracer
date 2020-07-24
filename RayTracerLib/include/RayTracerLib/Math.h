#pragma once

#include <Eigen/Core>

#define LARGE_VAL 1.0e+30
#define PI 3.141592653589

namespace RayTracer {

	using V3D = Eigen::Vector3d;
	double fdiv(double a, double b);

	int signum(double x);

	// Computes (1-mix) * a + mix * b
	double mix(double a, double b, double mix);
}