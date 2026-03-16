#include "Direction.hpp"
#include <catch2/catch_test_macros.hpp>
#include <format>

TEST_CASE("Direction", "[Direction]") {
  constexpr Direction up{Direction::Type::Up};
  REQUIRE(up.value == Direction::Type::Up);
  REQUIRE(std::format("{}", up) == "Up");
  REQUIRE((-up).value == Direction::Type::Down);
  REQUIRE(std::format("{}", -up) == "Down");

  constexpr Direction left{Direction::Type::Left};
  REQUIRE(left.value == Direction::Type::Left);
  REQUIRE(std::format("{}", left) == "Left");
  REQUIRE((-left).value == Direction::Type::Right);
  REQUIRE(std::format("{}", -left) == "Right");
}
