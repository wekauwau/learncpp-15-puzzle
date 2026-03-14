#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <termios.h>
#include <unistd.h>

// Keep it on the stack

#ifndef BOARD_WIDTH
#define BOARD_WIDTH 4
#endif

#ifndef BOARD_HEIGHT
#define BOARD_HEIGHT 4
#endif

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

void printStep(int step) { std::cout << step << " step" << (step < 2 ? " " : "s "); }

int main() {
  Board<BOARD_WIDTH, BOARD_HEIGHT> board;
  board.shuffle();

  std::cout << "Welcome to " << (BOARD_WIDTH * BOARD_HEIGHT) - 1 << "-Puzzle!\n"
            << "Now, solve this shit!\n"
            << "w/a/s/d to slide the tile, q to quit.\n"
            << board << '\n';

  int step{0};
  while (!board.isSolved()) {
    std::cout << "Enter a command: ";
    auto input{getChar()};

    if (input == 'q') {
      std::cout << "\n\n";
      printStep(step);
      std::cout << "of despair...\n"
                << "Bye!\n\n";

      return 0;
    }

    auto direction{Direction::from(input)};
    if (!direction)
      std::cout << "🤡💩\n";
    else if (!board.slide(*direction))
      std::cout << "🦍💩\n";
    else {
      std::cout << '\n' << BoardView{board} << '\n';
      ++step;
    }
  }

  std::cout << "\n\n"
            << "GGWP!\n";
  printStep(step);
  std::cout << "though.\n\n";

  return 0;
}
