#include "Tile.hpp"
#include <catch2/catch_test_macros.hpp>
#include <format>

TEST_CASE("Empty Tile or default Tile (num == 0)", "[Tile]") {
  constexpr Tile t{};
  REQUIRE(t.num == 0);
  REQUIRE(t.isEmpty());
  REQUIRE(std::format("{}", t) == "    ");
}

TEST_CASE("Tile with 1-digit value", "[Tile]") {
  constexpr Tile t{7};
  REQUIRE(t.num == 7);
  REQUIRE_FALSE(t.isEmpty());
  REQUIRE(std::format("{}", t) == "  7 ");
}

TEST_CASE("Tile with 2-digit value", "[Tile]") {
  constexpr Tile t{13};
  REQUIRE(t.num == 13);
  REQUIRE_FALSE(t.isEmpty());
  REQUIRE(std::format("{}", t) == " 13 ");
}
