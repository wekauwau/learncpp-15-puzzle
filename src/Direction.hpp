#pragma once

#include <optional>
#include <ostream>
#include <wekauwau/random.hpp>

struct Direction {
  enum class Type { Up, Left, Down, Right };

  static std::optional<Direction> from(char c) {
    switch (c) {
    case 'w':
      return Direction{Type::Up};
    case 'a':
      return Direction{Type::Left};
    case 's':
      return Direction{Type::Down};
    case 'd':
      return Direction{Type::Right};
    default:
      return std::nullopt;
    }
  }

  Type direction;

  Direction operator-() const;

  static Direction random() { return {static_cast<Type>(wkw::random::get(0, 3))}; }
};

std::ostream& operator<<(std::ostream& out, Direction::Type t);

inline std::ostream& operator<<(std::ostream& out, Direction d) { return out << d.direction; }
