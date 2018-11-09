#pragma once

#include "ray.hpp"

struct Hit {
  Vec3 position;
  Vec3 normal;
  float distance;
};

class Shape {
 public:
  virtual bool hit(
    Ray ray,
    float min_distance,
    float max_distance,
    Hit *out_hit) = 0;
};
