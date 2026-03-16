#include "Board.hpp"
#include "Point.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Default Board", "[Board]") {
  auto result = Board::create();
  REQUIRE(result);

  Board& b = *result;
  REQUIRE(b.size.height == 4);
  REQUIRE(b.size.width == 4);
  REQUIRE(b.size.size == 16);
  REQUIRE(b.getEmptyTile() == Point{3, 3});
}

TEST_CASE("5x7 Board", "[Board]") {
  auto result = Board::create(5, 7);
  REQUIRE(result);

  Board& b = *result;
  REQUIRE(b.size.height == 7);
  REQUIRE(b.size.width == 5);
  REQUIRE(b.size.size == 35);
  REQUIRE(b.getEmptyTile() == Point{6, 4});
}
