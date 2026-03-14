#include "Direction.hpp"
#include <utility>

Direction Direction::operator-() const {
  switch (direction) {
  case Type::Up:
    return {Type::Down};
  case Type::Down:
    return {Type::Up};
  case Type::Left:
    return {Type::Right};
  case Type::Right:
    return {Type::Left};
  }

  std::unreachable();
}

std::ostream& operator<<(std::ostream& out, Direction::Type t) {
  switch (t) {
  case Direction::Type::Up:
    return out << "Up";
  case Direction::Type::Down:
    return out << "Down";
  case Direction::Type::Left:
    return out << "Left";
  case Direction::Type::Right:
    return out << "Right";
  }

  std::unreachable();
}
