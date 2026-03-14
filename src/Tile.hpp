#pragma once

#include <cstddef>
#include <format>
#include <ostream>
#include <string>

struct Tile {
  std::size_t num{0};

  operator std::string() const { return isEmpty() ? "    " : std::format(" {:>2} ", num); }

  bool isEmpty() const { return num == 0; }
};

inline std::ostream& operator<<(std::ostream& out, Tile t) {
  return t.isEmpty() ? out << "    " : out << std::format(" {:>2} ", t.num);
}
