#pragma once

#include "vec3.hpp"

class Ray {
 public:
  Vec3 origin;
  Vec3 direction;

  Ray(Vec3 origin, Vec3 direction) :
    origin(origin), direction(direction) {}

  Vec3 pointAt(float distance);
};
