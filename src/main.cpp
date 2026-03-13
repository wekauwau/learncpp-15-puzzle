#include "Board.hpp"
#include <iostream>

int main() {
  Board<4, 4> board;
  std::cout << board << '\n';

  Board<3, 5> hmm;
  std::cout << hmm << '\n';

  return 0;
}
