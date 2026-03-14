#include "Board.hpp"
#include <array>
#include <iostream>
#include <variant>

// Keep it on the stack

int main() {
  using AnyBoard = std::variant<Board<4, 4>, Board<3, 5>, Board<4, 6>>;
  std::array<AnyBoard, 3> boards{Board<4, 4>{}, Board<3, 5>{}, Board<4, 6>{}};
  // std::array<AnyBoard, 1> boards{Board<4, 4>{}};

  for (auto& b : boards)
    std::visit(
        [](auto& board) {
          std::cout << board << '\n'
                    << "This board is " << (board.isSolved() ? "" : "not ") << "solved" << '\n'
                    << "Empty tile is in " << board.getEmptyTile() << '\n'
                    << "Shuffling...\n\n";

          board.shuffle();
          std::cout << board << '\n'
                    << "This board is shuffled, ready to play!\n"
                    << "Empty tile is in " << board.getEmptyTile() << "\n\n\n\n\n";
        },
        b);

  return 0;
}
