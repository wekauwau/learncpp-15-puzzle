#include "Board.hpp"
#include "Direction.hpp"
#include <array>
#include <iostream>
#include <variant>

// Keep it on the stack

int main() {
  using AnyBoard = std::variant<Board<4, 4>, Board<3, 5>, Board<4, 6>>;
  // std::array<AnyBoard, 3> boards{Board<4, 4>{}, Board<3, 5>{}, Board<4, 6>{}};
  std::array<AnyBoard, 1> boards{Board<4, 4>{}};

  for (auto& b : boards)
    std::visit(
        [](auto& board) {
          std::cout << board << '\n';
          std::cout << "This board is " << (board.isSolved() ? "" : "not ") << "solved" << '\n'
                    << "Empty tile is in " << board.getEmptyTile() << "\n\n";

          std::array<Direction::Type, 4> dirTest{Direction::Type::Right, Direction::Type::Down,
                                                 ::Direction::Type::Left, Direction::Type::Up};
          for (const auto& direction : dirTest) {
            std::cout << "Sliding " << direction << "...\n";
            if (board.slide(direction))
              std::cout << BoardView{board};
            else
              std::cout << "🦍💩  ";
            std::cout << '\n' << "Empty tile is in " << board.getEmptyTile() << '\n';
          }
          std::cout << '\n';

          std::cout << "Test wrong direction :\n";
          std::array<Direction::Type, 2> dirTest0{Direction::Type::Left, Direction::Type::Up};
          for (const auto& direction : dirTest0) {
            std::cout << "Sliding " << direction << "...\n";
            if (board.slide(direction))
              std::cout << BoardView{board};
            else
              std::cout << "🦍💩  ";
            std::cout << '\n' << "Empty tile is in " << board.getEmptyTile() << '\n';
          }
          std::cout << '\n';
        },
        b);

  return 0;
}
