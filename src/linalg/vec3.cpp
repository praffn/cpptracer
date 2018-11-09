#include <iostream>
#include <cmath>

#include "vec3.hpp"

namespace tracer::linalg {

float fround(float n, int precision) {
  int decimals = std::pow(10, precision);
  return (std::round(n * decimals)) / decimals;
}

Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

std::ostream& operator<<(std::ostream& o, const Vec3& v) {
  o << "Vec3 [" << v.x << ", " << v.y << ", " << v.z << "]";
  return o;
}

void Vec3::round(int precision) {
  x = fround(x, precision);
  y = fround(y, precision);
  z = fround(z, precision);
}

Vec3 Vec3::operator+(const Vec3& v) const {
  return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const {
  return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3& Vec3::operator+=(const Vec3& v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

Vec3 Vec3::operator*(const float s) const {
  return Vec3(x * s, y * s, z * s);
}
Vec3& Vec3::operator*=(const float s) {
  x *= s;
  y *= s;
  z *= s;
  return *this;
}

bool operator==(const Vec3& v, const Vec3& w) {
  return (
    v.x == w.x &&
    v.y == w.y &&
    v.z == w.z);
}
bool operator!=(const Vec3& v, const Vec3& w) {
  return !(v == w);
}

Vec3 Vec3::normalize_copy() const {
  float mag_inv = 1.0 / mag();
  return (*this) * mag_inv;
}

void Vec3::normalize() {
  float mag_inv = 1.0 / mag();
  x *= mag_inv;
  y *= mag_inv;
  z *= mag_inv;
}

float Vec3::dot(const Vec3 &o) const {
  return x*o.x + y*o.y + z*o.z;
}

float Vec3::mag2() const {
  return x*x + y*y + z*z;
}

float Vec3::mag() const {
  return sqrtf(mag2());
}

}
