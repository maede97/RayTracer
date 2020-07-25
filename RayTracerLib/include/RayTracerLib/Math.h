#pragma once

#include <Eigen/Core>

#define LARGE_VAL 1.0e+30 ///< Large value
#define PI 3.141592653589 ///< PI definition

namespace RayTracer {

	using V3D = Eigen::Vector3d; ///< Vector of three doubles

	/**
	 * @brief Signum of a number
	 * @param x The value to take the signum from
	 * @return 0 if x = 0, -1 if x < 0, 1 if x > 0
	 */
	int signum(double x);

	/**
	 * @brief Computes (1-mix) * a + mix * b
	 * @param a First input
	 * @param b Second input
	 * @param mix value to blend those two doubles
	 * @return (1-mix) * a + mix * b
	 */
	double mix(double a, double b, double mix);
}