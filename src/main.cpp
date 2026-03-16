#include "Board.hpp"
#include <iostream>
#include <print>

int main() {
  std::size_t width{}, height{};
  std::print("Enter width and height: ");
  std::cin >> width >> height;

  auto result = Board::create(width, height);
  if (!result) {
    std::println("Error: {}", result.error());
    return 1;
  }

  Board& board = *result;
  board.print();

  return 0;
}
