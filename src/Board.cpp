#include "Board.hpp"
#include <cassert>

Tile::Tile(std::size_t num) : m_num{num} { assert(num < boardNumMax); }

std::ostream& operator<<(std::ostream& out, const Tile& t) {
  out << (t.m_num < 10 ? "  " : " ");
  if (!t.isEmpty())
    out << t.m_num;
  else
    out << ' ';

  return out << ' ';
}

std::ostream& operator<<(std::ostream& out, const Board& o) {
  for (int i{0}; i < Board::s_consoleLines; ++i)
    out << '\n';

  for (const auto& row : o.m_tiles) {
    for (const auto& col : row)
      out << col;
    out << '\n';
  }

  return out;
}

bool Board::isSolved() const {
  std::size_t expected{1};

  for (const auto& row : m_tiles) {
    for (const auto& tile : row) {
      if (expected == boardNumMax)
        return tile.getNum() == 0;

      if (tile.getNum() != expected)
        return false;

      ++expected;
    }
  }

  return true;
}
