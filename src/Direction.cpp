#include "Direction.hpp"

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
