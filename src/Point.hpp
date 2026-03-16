#pragma once

#include "Direction.hpp"
#include <cstddef>
#include <utility>

struct Point {
  std::size_t row;
  std::size_t col;

  constexpr bool operator==(this Point, Point) = default;

  constexpr Point getAdjacent(Direction d) const noexcept {
    switch (d.value) {
    case Direction::Type::Up:
      return {row - 1, col};
    case Direction::Type::Left:
      return {row, col - 1};
    case Direction::Type::Down:
      return {row + 1, col};
    case Direction::Type::Right:
      return {row, col + 1};
    }

    std::unreachable();
  }
};
