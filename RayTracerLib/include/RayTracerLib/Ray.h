#pragma once

#include <RayTracerLib/Math.h>

namespace RayTracer {

	/**
	 * @brief Class for a Ray
	 */
	class Ray {
	public:
		/**
		 * @brief Default constructor, set origin to Zero and direction to be in X-positive
		 */
		Ray();

		/**
		 * @brief Construct a ray from given origin and direction
		 * @param origin The origin of this ray
		 * @param direction The direction of this ray
		 */
		Ray(V3D origin, V3D direction);

		/**
		 * @brief Get the origin of this Ray
		 * @return The origin
		 */
		V3D getOrigin() const;

		/**
		 * @brief Get the direction of this Ray
		 * @return The direction
		 */
		V3D getDirection() const;

	private:
		V3D origin = V3D::Zero(); ///< origin of this ray
		V3D direction = V3D(1.0,0.0,0.0); ///< direction of this ray
	};

};