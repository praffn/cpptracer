#pragma once

#include <iostream>

namespace tracer::linalg {

class Vec3 {
 private:
  float x, y, z;

 public:
  Vec3();
  Vec3(float x, float y, float z);

  // equality
  friend bool operator==(const Vec3&, const Vec3&);
  friend bool operator!=(const Vec3&, const Vec3&);

  // rounding/precisioning
  void round(int precision);

  // vector arithmetic
  Vec3 operator+(const Vec3& v) const;
  Vec3 operator-(const Vec3& v) const;
  Vec3& operator+=(const Vec3& v);
  Vec3& operator-=(const Vec3& v);

  // scalar arithmetic
  Vec3 operator*(const float s) const;
  Vec3& operator*=(const float s);

  // vector operations
  float mag2() const;
  float mag() const;
  float dot(const Vec3& v) const;
  Vec3 cross(const Vec3& v) const;
  Vec3 normalize_copy() const;
  void normalize();

  friend std::ostream& operator<<(std::ostream& o, const Vec3& v);
};

}
