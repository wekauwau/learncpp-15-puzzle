#include "Board.hpp"
#include <iostream>

int main() {
  Board<4, 4> board;
  std::cout << board << '\n' << board.isSolved() << '\n';

  Board<3, 5> hmm;
  std::cout << hmm << '\n' << board.isSolved() << '\n';

  return 0;
}
