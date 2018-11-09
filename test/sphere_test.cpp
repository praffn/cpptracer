#include "catch.hpp"
#include "../src/linalg/vec3.hpp"
#include "../src/geom/shape.hpp"
#include "../src/geom/sphere.hpp"

using namespace tracer::linalg;
using namespace tracer::geom;

TEST_CASE("ray should hit sphere") {
  Sphere s(
    Vec3(0.0, 0.0, 2.0),
    1.0);
  Ray ray(
    Vec3(0.0, 0.0, 0.0),
    Vec3(0.0, 0.0, 1.0));

  Hit hit;
  bool hits = s.hit(ray, 0, 100, &hit);
  REQUIRE(hits);
  REQUIRE(hit.distance == 1.0);
}
