#include "Tile.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Tile default is empty", "[tile]") {
  Tile t{};
  REQUIRE(t.isEmpty());
  REQUIRE(t.value() == 0);
}

TEST_CASE("Tile with value", "[tile]") {
  Tile t{7};
  REQUIRE_FALSE(t.isEmpty());
  REQUIRE(t.value() == 7);
}

TEST_CASE("Tile comparison", "[tile]") {
  REQUIRE(Tile{1} < Tile{2});
  REQUIRE(Tile{5} == Tile{5});
}
