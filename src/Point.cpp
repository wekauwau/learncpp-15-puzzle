#include "Point.hpp"

Point Point::getAdjacent(Direction d) const {
  // Point doesn't have invariants, return it as it is
  switch (d.direction) {
  case Direction::Type::Up:
    return Point{row - 1, col};
  case Direction::Type::Down:
    return Point{row + 1, col};
  case Direction::Type::Left:
    return Point{row, col - 1};
  case Direction::Type::Right:
    return Point{row, col + 1};
  }

  return {};
}
