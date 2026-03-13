#pragma once

#include "Direction.hpp"
#include <cstddef>
#include <ostream>

struct Point {
  std::size_t row{0};
  std::size_t col{0};

  Point getAdjacent(const Direction& d) const;
};

inline std::ostream& operator<<(std::ostream& out, const Point& p) {
  return out << '(' << p.row << ", " << p.col << ')';
}
