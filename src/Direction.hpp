#pragma once

#include <ostream>
#include <wekauwau/random.hpp>

struct Direction {
  enum class Type { Up, Left, Down, Right };

  Type direction;

  Direction operator-() const;

  static Direction random() { return {static_cast<Type>(wkw::random::get(0, 3))}; }
};

std::ostream& operator<<(std::ostream& out, Direction::Type t);

inline std::ostream& operator<<(std::ostream& out, const Direction& d) {
  return out << d.direction;
}
