#pragma once

#include <cstddef>
#include <ostream>

class Tile {
public:
  Tile() = default;
  explicit Tile(std::size_t num) : m_num{num} {}

  std::size_t getNum() const { return m_num; }

  friend std::ostream& operator<<(std::ostream& out, const Tile& t);

  bool isEmpty() const { return m_num == 0; }

private:
  std::size_t m_num{0};
};
