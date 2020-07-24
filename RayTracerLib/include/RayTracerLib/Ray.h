#pragma once

#include <RayTracerLib/Math.h>

namespace RayTracer {

	class Ray {
	public:
		Ray();
		Ray(V3D origin, V3D direction);

		V3D getOrigin() const;
		V3D getDirection() const;

	private:
		V3D origin = V3D::Zero();
		V3D direction = V3D(1.0,0.0,0.0);
	};

};