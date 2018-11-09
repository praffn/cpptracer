#include <iostream>
#include "vec3.hpp"
#include "sphere.hpp"
#include "ray.hpp"
#include "shape.hpp"

int main() {
  Sphere sphere(
    Vec3(0.0, 0.0, 3.0),
    2.5);

  Ray ray(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 1.0).normalize_copy());

  Hit hit;
  if (sphere.hit(ray, 1.0, 100.0, &hit)) {
    std::cout << "hit! distance: " << hit.distance << std::endl;
  } else {
    std::cout << "no hit!" << std::endl;
  }
}
