#include "ray.hpp"

Vec3 Ray::pointAt(float distance) {
  return (origin + direction) * distance;
}
