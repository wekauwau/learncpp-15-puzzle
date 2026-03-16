#include "Board.hpp"
#include <cstdlib>
#include <iostream>
#include <print>
#include <termios.h>
#include <unistd.h>

char getChar() {
  termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~static_cast<tcflag_t>(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  char c{static_cast<char>(getchar())};
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return c;
}

int main() {
  std::print("Welcome boss!\nEnter the board width and height (separated by space, both W and H "
             "must be > 1) : ");
  std::size_t width{}, height{};
  std::cin >> width >> height;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  auto result{Board::create(width, height)};
  if (!result) {
    std::println("🦍💩\nBye! 🤡");
    return EXIT_FAILURE;
  }

  Board& board{*result};
  board.shuffle();
  std::println("\nNow, solve this shit!\nCommand is w/a/s/d, q to exit.\n");
  for (int i{0}; i < 25; ++i)
    std::println();
  board.print();

  int step{0};
  auto printStep = [&]() -> std::string {
    return std::format("{} {}", step, step < 2 ? "step" : "steps");
  };

  while (!board.isSolved()) {
    std::print("Enter a command: ");
    auto input{getChar()};
    std::println();

    if (input == 'q') {
      std::println("\n{} of despair...\nBye! 🤡🤡", printStep());
      return EXIT_SUCCESS;
    }

    auto direction{Direction::from(input)};
    if (!direction)
      std::cout << "🤡💩\n";
    else if (!board.slide(*direction))
      std::cout << "🦍💩\n";
    else {
      board.print(true);
      ++step;
    }
  }

  std::println("\nGGWP!\n{} though.", printStep());

  return EXIT_SUCCESS;
}
