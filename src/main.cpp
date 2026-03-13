#include "Board.hpp"
#include "Direction.hpp"
#include "Point.hpp"
#include <array>
#include <iostream>
#include <variant>

// Keep it on the stack

int main() {
  using AnyBoard = std::variant<Board<4, 4>, Board<3, 5>, Board<4, 6>>;
  std::array<AnyBoard, 3> boards{Board<4, 4>{}, Board<3, 5>{}, Board<4, 6>{}};

  for (const auto& b : boards)
    std::visit(
        [](const auto& board) {
          Point emptyTile{board.getEmptyTile()};

          std::cout << board << '\n';
          std::cout << "This board is " << (board.isSolved() ? "" : "not ") << "solved" << "\n\n";

          for (int i{0}; i < 4; ++i) {
            Direction direction{static_cast<Direction::Type>(i)};
            auto adjacentTile{board.getTile(Point{0, 0}.getAdjacent(direction))};

            std::cout << "Adjacent " << direction << " of first tile is ";
            if (adjacentTile)
              std::cout << *adjacentTile;
            else
              std::cout << "invalid";
            std::cout << '\n';
          }
          std::cout << '\n';

          std::cout << "Empty tile is in " << emptyTile << '\n';
          for (int i{0}; i < 4; ++i) {
            Direction direction{static_cast<Direction::Type>(i)};
            auto adjacentTile{board.getTile(emptyTile.getAdjacent(direction))};

            std::cout << "Adjacent " << direction << " of empty tile is ";
            if (adjacentTile)
              std::cout << *adjacentTile;
            else
              std::cout << "invalid";
            std::cout << '\n';
          }
        },
        b);

  return 0;
}
