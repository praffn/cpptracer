#include <iostream>

#include "linalg/vec3.hpp"
#include "linalg/ray.hpp"
#include "geom/shape.hpp"
#include "geom/sphere.hpp"

using namespace tracer;

int main() {
  geom::Sphere sphere(
    linalg::Vec3(0.0, 0.0, 3.0),
    2.5);

  linalg::Ray ray(
    linalg::Vec3(0.0, 0.0, 0.0),
    linalg::Vec3(0.0, 0.0, 1.0).normalize_copy());

  geom::Hit hit;
  if (sphere.hit(ray, 1.0, 100.0, &hit)) {
    std::cout << "hit! distance: " << hit.distance << std::endl;
  } else {
    std::cout << "no hit!" << std::endl;
  }
}
