#include <RayTracerLib/Utils.h>

int main(int argc, char** argv) {

    std::vector<RayTracer::Shape*> shapes;

    shapes.push_back(new RayTracer::Sphere(RayTracer::V3D(0.0, -10004.0, -20.0), 10000.0, 0.0, 0.0, RayTracer::Color(0.2, 0.2, 0.2), RayTracer::Color()));
    shapes.push_back(new RayTracer::Cube(RayTracer::V3D(-4.0, -4.0, -24.0), RayTracer::V3D(0.0, 0.0, -16.0), 0.1, 0.1, RayTracer::Color(0.5,1.0,0.78), RayTracer::Color(0.0,0.0,0.0)));
    shapes.push_back(new RayTracer::Sphere(RayTracer::V3D(5.0, -1.0, -15.0), 2.0, 1.0, 0.0, RayTracer::Color(0.9, 0.76, 0.46), RayTracer::Color()));
    shapes.push_back(new RayTracer::Sphere(RayTracer::V3D(-5.5, 0.0, -15.0), 3.0, 1.0, 0.0, RayTracer::Color(0.9, 0.9, 0.9), RayTracer::Color()));

    // light
    shapes.push_back(new RayTracer::Sphere(RayTracer::V3D(-10.0, 20.0, -30.0), 3.0, 0.0, 0.0, RayTracer::Color(0.0, 0.0, 0.0), RayTracer::Color(3.0, 3.0, 3.0)));

    RayTracer::Utils::render(shapes, 640, 480, 10, "cubes.ppm");

    for (auto& s : shapes) {
        delete s;
    }

    return 0;
}