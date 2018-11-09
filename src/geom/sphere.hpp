#pragma once

#include "shape.hpp"

namespace tracer::geom {

class Sphere : public Shape {
 private:
  linalg::Vec3 center;
  float radius;
 public:
  Sphere(linalg::Vec3 center, float radius);

  bool hit(
    linalg::Ray ray,
    float min_distance,
    float max_distance,
    Hit *out_hit);
};

}  // namespace tracer::geom
