#pragma once

#include <cstddef>

struct Point {
  std::size_t row;
  std::size_t col;

  constexpr bool operator==(this Point, Point) = default;
};
