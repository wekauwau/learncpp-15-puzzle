#pragma once

#include <format>

struct Tile {
  unsigned int num{0};

  [[nodiscard]] constexpr bool isEmpty() const noexcept { return num == 0; }
};

template <>
struct std::formatter<Tile> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

  auto format(Tile t, std::format_context& ctx) const {
    if (t.isEmpty())
      return std::format_to(ctx.out(), "    ");
    return std::format_to(ctx.out(), " {:>2} ", t.num);
  }
};
