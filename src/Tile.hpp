#pragma once

#include <cstddef>
#include <ostream>

struct Tile {
  std::size_t num{0};

  bool isEmpty() const { return num == 0; }
};

inline std::ostream& operator<<(std::ostream& out, const Tile& t) {
  out << (t.num < 10 ? "  " : " ");
  if (!t.isEmpty())
    out << t.num;
  else
    out << ' ';

  return out << ' ';
}
