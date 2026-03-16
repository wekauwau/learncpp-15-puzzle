#include "Board.hpp"
#include <print>
#include <utility>

std::expected<Board, std::string_view> Board::create(std::size_t width,
                                                     std::size_t height) noexcept {
  if (width <= 1 || height <= 1)
    return std::unexpected{"Dimensions must be > 1"};
  return Board{width, height};
}

bool Board::isSolved() const noexcept {
  std::size_t expected{0};
  for (const auto& row : m_tiles)
    for (auto tile : row) {
      if (++expected == size.size)
        return tile.isEmpty();

      if (tile.num != expected)
        return false;
    }

  return true;
}

void Board::print(bool highlight) const noexcept {
  static constexpr std::string_view BOLD_RED = "\033[1;31m";
  static constexpr std::string_view RESET = "\033[0m";

  for (std::size_t row{0}; row <= size.maxRowIndex(); ++row) {
    for (std::size_t col{0}; col <= size.maxColIndex(); ++col) {
      bool isHighlighted = highlight && (Point{row, col} == m_lastMovedTile);

      if (isHighlighted)
        std::print("{}", BOLD_RED);
      std::print("{}", m_tiles[row][col]);
      if (isHighlighted)
        std::print("{}", RESET);
    }
    std::println("");
  }
}

bool Board::slide(Direction d) noexcept {
  Point newPoint{m_emptyTile.getAdjacent(-d)};
  if (inBounds(newPoint)) {
    std::swap(tileAt(m_emptyTile), tileAt(newPoint));
    m_lastMovedTile = m_emptyTile;
    m_emptyTile = newPoint;
    return true;
  }

  return false;
}

Board::Board(std::size_t width, std::size_t height)
    : size{width, height, width * height}, m_tiles(height, std::vector<Tile>(width)),
      m_emptyTile{size.maxRowIndex(), size.maxColIndex()}, m_lastMovedTile{m_emptyTile} {
  assert(width > 1 && height > 1);

  unsigned int val{0};
  for (auto& row : m_tiles)
    for (auto& tile : row)
      tile = Tile{++val};
  m_tiles[size.maxRowIndex()][size.maxColIndex()] = Tile{0};
}
