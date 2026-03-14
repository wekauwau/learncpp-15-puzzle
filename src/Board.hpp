#pragma once

// GOD FORSAKEN CODE

#include "Direction.hpp"
#include "Point.hpp"
#include "Tile.hpp"
#include "wekauwau/output.hpp"
#include <array>
#include <cstddef>
#include <ostream>

// For friend
template <std::size_t WIDTH, std::size_t HEIGHT>
struct BoardView;

template <typename T, std::size_t ROW, std::size_t COL>
using Array2D = std::array<std::array<T, COL>, ROW>;

template <std::size_t WIDTH, std::size_t HEIGHT>
class Board {
  static_assert(WIDTH > 1 && HEIGHT > 1);
  friend struct BoardView<WIDTH, HEIGHT>;

public:
  Board() : m_tiles{} {
    std::size_t num{0};
    for (auto& row : m_tiles)
      for (Tile& tile : row)
        tile = Tile{++num};

    m_tiles[HEIGHT - 1][WIDTH - 1] = Tile{0};
  }

  Point getEmptyTile() const { return m_emptyTile; }

  friend std::ostream& operator<<(std::ostream& out, const Board& o) {
    // static constexpr int s_consoleLines{3};
    // for (int i{0}; i < s_consoleLines; ++i)
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
      for (Tile tile : row) {
        if (++expected == m_size)
          return tile.isEmpty();

        if (tile.num != expected)
          return false;
      }

    return true;
  }

  bool isValidPoint(Point p) const {
    if (p.row >= m_row || p.col >= m_col)
      return false;
    return true;
  }

  void shuffle(int n = 1000) {
    for (int i{0}; i < n; ++i)
      slide(Direction::random());
  }

  bool slide(Direction d) {
    Point newPoint{m_emptyTile.getAdjacent(-d)};

    if (isValidPoint(newPoint)) {
      std::swap(m_tiles[m_emptyTile.row][m_emptyTile.col], m_tiles[newPoint.row][newPoint.col]);
      m_lastMovedTile = m_emptyTile;
      m_emptyTile = newPoint;

      return true;
    }

    return false;
  }
  bool slide(Direction::Type t) { return slide(Direction{t}); }

private:
  Array2D<Tile, HEIGHT, WIDTH> m_tiles;
  Point m_emptyTile{HEIGHT - 1, WIDTH - 1};
  Point m_lastMovedTile{m_emptyTile};
  std::size_t m_row{HEIGHT};
  std::size_t m_col{WIDTH};
  std::size_t m_size{WIDTH * HEIGHT};
};

template <std::size_t WIDTH, std::size_t HEIGHT>
struct BoardView {
  const Board<WIDTH, HEIGHT>& board;

  friend std::ostream& operator<<(std::ostream& out, BoardView b) {
    out << '\n';

    for (std::size_t row{0}; row < HEIGHT; ++row) {
      for (std::size_t col{0}; col < WIDTH; ++col) {
        Tile tile{b.board.m_tiles[row][col]};

        if (Point{row, col} == b.board.m_lastMovedTile)
          out << wkw::output::Highlight{static_cast<std::string>(tile)};
        else
          out << tile;
      }
      out << '\n';
    }

    return out;
  }
};
