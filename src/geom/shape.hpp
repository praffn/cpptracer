#pragma once

#include "../linalg/ray.hpp"

namespace tracer::geom {

struct Hit {
  linalg::Vec3 position;
  linalg::Vec3 normal;
  float distance;
};

class Shape {
 public:
  virtual bool hit(
    linalg::Ray ray,
    float min_distance,
    float max_distance,
    Hit *out_hit) = 0;
};

}  // namespace tracer::geom
