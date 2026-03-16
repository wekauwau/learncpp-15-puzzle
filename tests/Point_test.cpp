#include "Direction.hpp"
#include "Point.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Default Point", "[Point]") {
  constexpr Point p{};
  REQUIRE(p.row == 0);
  REQUIRE(p.col == 0);

  constexpr auto up{p.getAdjacent(Direction{Direction::Type::Up})};
  REQUIRE_FALSE(up.row == 1);
  REQUIRE(up.col == 0);

  constexpr auto left{p.getAdjacent(Direction{Direction::Type::Left})};
  REQUIRE(left.row == 0);
  REQUIRE_FALSE(left.col == 1);

  constexpr auto down{p.getAdjacent(Direction{Direction::Type::Down})};
  REQUIRE(down.row == 1);
  REQUIRE(down.col == 0);

  constexpr auto right{p.getAdjacent(Direction{Direction::Type::Right})};
  REQUIRE(right.row == 0);
  REQUIRE(right.col == 1);
}

TEST_CASE("Point{3, 2}", "[Point]") {
  constexpr Point p{3, 2};
  REQUIRE(p.row == 3);
  REQUIRE(p.col == 2);

  constexpr auto up{p.getAdjacent(Direction{Direction::Type::Up})};
  REQUIRE(up.row == 2);
  REQUIRE(up.col == 2);

  constexpr auto left{p.getAdjacent(Direction{Direction::Type::Left})};
  REQUIRE(left.row == 3);
  REQUIRE(left.col == 1);

  constexpr auto down{p.getAdjacent(Direction{Direction::Type::Down})};
  REQUIRE(down.row == 4);
  REQUIRE(down.col == 2);

  constexpr auto right{p.getAdjacent(Direction{Direction::Type::Right})};
  REQUIRE(right.row == 3);
  REQUIRE(right.col == 3);
}

TEST_CASE("Point operator==", "[Point]") {
  constexpr Point p{3, 3};
  REQUIRE_FALSE(p == Point{});
  REQUIRE(p == Point{3, 3});
}
