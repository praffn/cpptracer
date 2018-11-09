#include <cmath>

#include "catch.hpp"
#include "vec3.hpp"

TEST_CASE("vector addition", "[vector]") {
  Vec3 a(1.0, 2.0, 3.0);
  Vec3 b(2.0, 3.0, -4.0);
  Vec3 expected(3.0, 5.0, -1.0);
  REQUIRE(a + b == expected);
  a += b;
  REQUIRE(a == expected);
}

TEST_CASE("vector subtraction", "[vector]") {
  Vec3 a(1.0, 2.0, 3.0);
  Vec3 b(2.0, 3.0, -4.0);
  Vec3 expected(-1.0, -1.0, 7.0);
  REQUIRE(a - b == expected);
  a -= b;
  REQUIRE(a == expected);
}

TEST_CASE("scalar multiplication", "[vector]") {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 expected(2.0, 4.0, 6.0);
  REQUIRE(v * 2.0 == expected);
  v *= 2.0;
  REQUIRE(v == expected);
}

TEST_CASE("vector rounding", "[vector]") {
  Vec3 v(1.111, 2.892, 3.0);
  Vec3 expected(1.1, 2.9, 3.0);
  v.round(1);
  REQUIRE(v == expected);
}

TEST_CASE("magnitude", "[vector]") {
  Vec3 v(1.0, 2.0, 3.0);
  REQUIRE(v.mag2() == 14.0);
  REQUIRE(v.mag() == Approx(3.742).margin(0.001));
}

TEST_CASE("normalization", "[vector]") {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 expected(0.267, 0.535, 0.802);
  Vec3 normal = v.normalize_copy();
  normal.round(3);
  REQUIRE(normal == expected);
  v.normalize();
  v.round(3);
  REQUIRE(v == expected);
}

TEST_CASE("dot product", "[vector]") {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 w(3.0, 2.0, 1.0);
  // v.mag2() should eq v.dot(v);
  REQUIRE(v.mag2() == v.dot(v));
  REQUIRE(v.dot(w) == 10.0);
}
