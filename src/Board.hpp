#pragma once

#include "Direction.hpp"
#include "Point.hpp"
#include "Tile.hpp"
#include <cassert>
#include <cstddef>
#include <expected>
#include <string_view>
#include <vector>

class Board {
  struct Size {
    std::size_t width;
    std::size_t height;
    std::size_t size;

    std::size_t maxColIndex() const noexcept { return width - 1; }
    std::size_t maxRowIndex() const noexcept { return height - 1; }
    std::size_t maxVal() const noexcept { return size - 1; }
  };

public:
  const Size size;

  // Factory
  static std::expected<Board, std::string_view> create(std::size_t width = 4,
                                                       std::size_t height = 4) noexcept;
  const Tile* operator[](Point p) const noexcept {
    if (!inBounds(p))
      return nullptr;
    return &m_tiles[p.row][p.col];
  }
  Point getEmptyTile() const noexcept { return m_emptyTile; }
  Point getLastMovedTile() const noexcept { return m_lastMovedTile; }

  void print(bool highlight = false) const noexcept;
  bool slide(Direction d) noexcept;

private:
  std::vector<std::vector<Tile>> m_tiles;
  Point m_emptyTile;
  Point m_lastMovedTile;

  Board(std::size_t width = 4, std::size_t height = 4);
  Tile& tileAt(Point p) noexcept { return m_tiles[p.row][p.col]; }

  bool inBounds(Point p) const noexcept {
    return p.row <= size.maxRowIndex() && p.col <= size.maxColIndex();
  }
};
