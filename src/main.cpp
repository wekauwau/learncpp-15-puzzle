#include "Direction.hpp"
#include <print>

int main() {
  for (int i{0}; i < 5; ++i) {
    Direction d{Direction::random()};
    std::println("{} x {}", d, -d);
  }

  return 0;
}
