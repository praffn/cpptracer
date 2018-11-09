#pragma once

#include "shape.hpp"

class Sphere : public Shape {
 private:
  Vec3 center;
  float radius;
 public:
  Sphere(Vec3 center, float radius);

  bool hit(
    Ray ray,
    float min_distance,
    float max_distance,
    Hit *out_hit);
};
