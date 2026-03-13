#include "Board.hpp"
#include <iostream>

int main() {
  Board board{};
  std::cout << board;
  std::cout << std::boolalpha << board.isSolved() << '\n';

  return 0;
}
