#pragma once

#include <array>
#include <cstddef>
#include <ostream>

template <typename T, std::size_t ROW, std::size_t COL>
using Array2D = std::array<std::array<T, COL>, ROW>;

class Tile {
public:
  explicit Tile(std::size_t num);

  std::size_t getNum() const { return m_num; }

  friend std::ostream& operator<<(std::ostream& out, const Tile& t);

  bool isEmpty() const { return m_num == 0; }

private:
  std::size_t m_num{};
};

class Board {
public:
  static constexpr std::size_t boardWidth{4};
  static constexpr std::size_t boardHeight{4};
  static constexpr auto boardNumMax{boardHeight * boardWidth};

  explicit Board() = default;

  friend std::ostream& operator<<(std::ostream& out, const Board& b);

  bool isSolved() const;
  // bool slide(const Direction& d);

private:
  static constexpr int s_consoleLines{3};
  // clang-format off
  Array2D<Tile, boardHeight, boardWidth> m_tiles{{
    {{ Tile{1}, Tile{2}, Tile{3}, Tile{4}, }},
    {{ Tile{5}, Tile{6}, Tile{7}, Tile{8}, }},
    {{ Tile{9}, Tile{10}, Tile{11}, Tile{12}, }},
    {{ Tile{13}, Tile{14}, Tile{15}, Tile{0}, }},
  }};
  // clang-format on
};
