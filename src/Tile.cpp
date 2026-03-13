#include "Tile.hpp"

std::ostream& operator<<(std::ostream& out, const Tile& t) {
  out << (t.m_num < 10 ? "  " : " ");
  if (!t.isEmpty())
    out << t.m_num;
  else
    out << ' ';

  return out << ' ';
}
