#pragma once

// THIS IS SUCH AN ABOMINATION

#include "Tile.hpp"
#include <array>
#include <cstddef>
#include <ostream>

template <typename T, std::size_t ROW, std::size_t COL>
using Array2D = std::array<std::array<T, COL>, ROW>;

template <std::size_t WIDTH, std::size_t HEIGHT>
class Board {
  static_assert(WIDTH > 1 && HEIGHT > 1);

public:
  Board() : m_tiles{} {
    std::size_t num{0};
    for (auto& row : m_tiles)
      for (Tile& tile : row)
        tile = Tile{++num};

    m_tiles[HEIGHT - 1][WIDTH - 1] = Tile{0};
  }

  friend std::ostream& operator<<(std::ostream& out, const Board& o) {
    static constexpr int s_consoleLines{3};
    for (int i{0}; i < s_consoleLines; ++i)
      out << '\n';

    for (const auto& row : o.m_tiles) {
      for (const auto& col : row)
        out << col;
      out << '\n';
    }

    return out;
  }

  bool isSolved() const {
    std::size_t expected{0};
    for (const auto& row : m_tiles)
      for (const Tile& tile : row) {
        if (++expected == m_size)
          return tile.isEmpty();

        if (tile.getNum() != expected)
          return false;
      }

    return true;
  }

private:
  Array2D<Tile, HEIGHT, WIDTH> m_tiles;
  std::size_t m_size{WIDTH * HEIGHT};
};
