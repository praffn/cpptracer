#pragma once

#include "vec3.hpp"

class Camera {
 private:
  Vec3 position;
  Vec3 up;
  Vec3 lookAt;
 public:
  Camera(Vec3 position, Vec3 up, Vec3 lookAt);
};
