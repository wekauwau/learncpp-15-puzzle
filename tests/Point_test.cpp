#include "Point.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Default Point", "[Point]") {
  constexpr Point p{};
  REQUIRE(p.row == 0);
  REQUIRE(p.col == 0);
}

TEST_CASE("Point{3, 2}", "[Point]") {
  constexpr Point p{3, 2};
  REQUIRE(p.row == 3);
  REQUIRE(p.col == 2);
}

TEST_CASE("Point operator==", "[Point]") {
  constexpr Point p{3, 3};
  REQUIRE_FALSE(p == Point{});
  REQUIRE(p == Point{3, 3});
}
