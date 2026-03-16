#pragma once

#include <format>
#include <optional>
#include <utility>
#include <wekauwau/random.hpp>

struct Direction {
  enum class Type { Up, Left, Down, Right };
  static constexpr int typeCount{4};

  constexpr explicit Direction(Type t) noexcept : value{t} {}

  static constexpr std::optional<Direction> from(char c) noexcept {
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

  Type value;

  constexpr Direction operator-() const noexcept {
    switch (value) {
    case Type::Up:
      return Direction{Type::Down};
    case Type::Left:
      return Direction{Type::Right};
    case Type::Down:
      return Direction{Type::Up};
    case Type::Right:
      return Direction{Type::Left};
    }

    std::unreachable();
  }

  static Direction random() {
    return Direction{static_cast<Type>(wkw::random::get(0, typeCount - 1))};
  }
};

template <>
struct std::formatter<Direction::Type> : std::formatter<std::string_view> {
  auto format(Direction::Type t, std::format_context& ctx) const {
    string_view name;
    switch (t) {
    case Direction::Type::Up:
      name = "Up";
      break;
    case Direction::Type::Left:
      name = "Left";
      break;
    case Direction::Type::Down:
      name = "Down";
      break;
    case Direction::Type::Right:
      name = "Right";
      break;
    default:
      name = "???";
      break;
    }
    return std::formatter<std::string_view>::format(name, ctx);
  }
};

template <>
struct std::formatter<Direction> : std::formatter<Direction::Type> {
  auto format(const Direction& d, std::format_context& ctx) const {
    return std::formatter<Direction::Type>::format(d.value, ctx);
  }
};
