#include "Point.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Default Point", "[Point]") {
  Point p{};
  REQUIRE(p.row == 0);
  REQUIRE(p.col == 0);
}

TEST_CASE("Point{3, 2}", "[Point]") {
  Point p{3, 2};
  REQUIRE(p.row == 3);
  REQUIRE(p.col == 2);
}
