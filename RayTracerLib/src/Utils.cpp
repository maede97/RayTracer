#include <RayTracerLib\Utils.h>
#include <RayTracerLib/Color.h>

#include <fstream>
#include <iostream>

#include <omp.h>

RayTracer::Color RayTracer::trace(const Ray& ray, const std::vector<Shape*>& shapes, const int& depth, const int MAX_RAY_DEPTH)
{
	double tnear = INFINITY;
	const Shape* shape = nullptr;
	V3D phit, nhit;

	for (unsigned i = 0; i < shapes.size(); i++) {
		double t0 = INFINITY;
		double t1 = INFINITY;

		// find intersection of this ray with a sphere
		if (shapes[i]->intersects(ray, t0, t1, phit, nhit)) {
			if (t0 < 0) t0 = t1;
			if (t0 < tnear) {
				tnear = t0;
				shape = shapes[i];
			}
		}
	}

	// if there is no intersection, return background color
	if (!shape) return Color(2., 2.0, 2.0);

	Color surfaceColor = Color(0, 0, 0);

	double bias = 1.0e-4;
	bool inside = false;

	if (ray.getDirection().dot(nhit) > 0) nhit = -nhit, inside = true;

	if ((shape->getTransparency() > 0 || shape->getReflection() > 0) && depth < MAX_RAY_DEPTH) {
		double facingratio = -ray.getDirection().dot(nhit);
		double fresnelEffect = mix(pow(1 - facingratio, 3), 1, 0.1);

		V3D reflDir = ray.getDirection() - nhit * 2 * ray.getDirection().dot(nhit);
		reflDir.normalize();

		Ray reflRay = Ray(phit + nhit * bias, reflDir);
		Color reflection = trace(reflRay, shapes, depth + 1, MAX_RAY_DEPTH);
		Color refraction;

		// if also transparent, compute refraction ray
		if (shape->getTransparency()) {
			double ior = 1.1, eta = (inside) ? ior : 1.0 / ior;
			double cosi = -nhit.dot(ray.getDirection());
			double k = 1.0 - eta * eta * (1.0 - cosi * cosi);
			V3D refrDir = ray.getDirection() * eta + nhit * (eta * cosi - sqrt(k));
			refrDir.normalize();
			Ray refrRay = Ray(phit - nhit * bias, refrDir);
			refraction = trace(refrRay, shapes, depth + 1, MAX_RAY_DEPTH);
		}

		surfaceColor = (reflection * fresnelEffect + refraction * (1.0 - fresnelEffect) * shape->getTransparency()) * shape->getSurfaceColor();
	}
	else {
		// it's a diffuse object, no need to raytrace further
		for (unsigned i = 0; i < shapes.size(); i++) {
			if (shapes[i]->getEmissionColor().getRed() > 0.0) {
				// this is a light
				V3D transmission = V3D::Ones();
				V3D lightDir = -nhit;
				lightDir.normalize();
				for (unsigned j = 0; j < shapes.size(); j++) {
					if (i != j) {
						double t0, t1;
						V3D phit_, nhit_;
						Ray emissionRay = Ray(phit + nhit * bias, lightDir);
						if (shapes[j]->intersects(emissionRay, t0, t1, phit_, nhit_)) {
							transmission.setZero();
							break;
						}
					}
				}
				surfaceColor = surfaceColor + shape->getSurfaceColor() * transmission * std::max(0.0, nhit.dot(lightDir)) * shapes[i]->getEmissionColor();
			}
		}
	}
	return surfaceColor + shape->getEmissionColor();
}

void RayTracer::render(const std::vector<Shape*>& shapes, unsigned width, unsigned height, const int MAX_RAY_DEPTH, const char* filename)
{
	std::vector<V3D> image;
	image.resize(width * height);

	double invWidth = 1.0 / double(width), invHeight = 1.0 / double(height);
	double fov = 30, aspectratio = width / double(height);
	double angle = tan(PI * 0.5 * fov / 180.0);

	// trace rays
#pragma omp parallel for shared(image, shapes, height, width, invWidth, angle, aspectratio, MAX_RAY_DEPTH)
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			double xx = (2.0 * ((x + 0.5) * invWidth) - 1.0) * angle * aspectratio;
			double yy = (1.0 - 2.0 * ((y + 0.5) * invHeight)) * angle;
			Ray ray = Ray(V3D::Zero(), V3D(xx, yy, -1).normalized());
			V3D col = trace(ray, shapes, 0, MAX_RAY_DEPTH).getColorVector();
#pragma omp critical (image)
			image[x + y * width] = col;
		}
	}

#pragma omp barrier

	// save file to a ppm
	std::ofstream ofs(filename, std::ios::out | std::ios::binary);
	ofs << "P6\n" << width << " " << height << "\n255\n";
	for (unsigned i = 0; i < width * height; i++) {
		V3D min = image[i].cwiseMin(1.0);
		ofs << (unsigned char)(min.x() * 255.0) <<
			(unsigned char)(min.y() * 255.0) <<
			(unsigned char)(min.z() * 255.0);
	}
	ofs.close();
}