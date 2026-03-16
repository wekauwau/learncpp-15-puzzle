#include "Board.hpp"
#include <print>

int main() {
  auto result{Board::create()};
  if (!result)
    return 1;

  Board& board{*result};

  std::println("This board is {}solved", (board.isSolved() ? "" : "not "));
  board.print();
  std::println();

  board.shuffle();
  std::println("This board is {}solved", (board.isSolved() ? "" : "not "));
  board.print(true);

  return 0;
}
