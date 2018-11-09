#include <cmath>

#include "sphere.hpp"

bool min_gt_zero(float a, float b, float *out) {
  if (a < 0.0 && b < 0.0) return false;
  *out = (a < b) ? a : b;
  return true;
}

Sphere::Sphere(Vec3 center, float radius) :
  center(center), radius(radius) {}

bool Sphere::hit(
  Ray ray,
  float min_distance,
  float max_distance,
  Hit *out_hit) {
  Vec3 o = ray.origin - center;
  float a = ray.direction.mag2();
  float b = o.dot(ray.direction) * 2.0;
  float c = o.mag2() - radius*radius;
  float disc = b*b - 4.0*a*c;
  if (disc >= 0.0) {
    float sqrt_disc = sqrtf(disc);
    float t1 = (-b + sqrt_disc) / (2.0*a);
    float t2 = (-b - sqrt_disc) / (2.0*a);
    return min_gt_zero(t1, t2, &out_hit->distance);
  }
  return false;
}
