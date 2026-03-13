#pragma once

#include <ostream>
#include <utility>
#include <wekauwau/random.hpp>

struct Direction {
  enum class Type { Up, Left, Down, Right };

  static std::string_view getTypeString(Type t) {
    switch (t) {
    case Type::Up:
      return "Up";
    case Type::Down:
      return "Down";
    case Type::Left:
      return "Left";
    case Type::Right:
      return "Right";
    }

    std::unreachable();
  }

  Type direction;

  Direction operator-() const;

  static Direction random() { return {static_cast<Type>(wkw::random::get(0, 3))}; }
};

inline std::ostream& operator<<(std::ostream& out, const Direction& d) {
  return out << Direction::getTypeString(d.direction);
}
