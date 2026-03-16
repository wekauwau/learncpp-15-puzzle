#include "Board.hpp"
#include "Direction.hpp"
#include <print>

int main() {
  auto result{Board::create()};
  if (!result)
    return 1;

  Board& board{*result};
  board.print();
  std::println();

  for (int i{0}; i < 5; ++i) {
    auto d{Direction::random()};
    std::println("Slide {}:", d);

    if (board.slide(d)) {
      board.print(true);
    } else {
      std::println("🤡");
    }

    std::println();
  }

  return 0;
}
