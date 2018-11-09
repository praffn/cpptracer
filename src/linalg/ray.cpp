#include "ray.hpp"

namespace tracer::linalg {

Vec3 Ray::pointAt(float distance) {
  return (origin + direction) * distance;
}

}
