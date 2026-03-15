#include <cassert>
#include <compare> // For operator<=>
#include <format>

class Tile {
public:
  using value_type = unsigned int;

  explicit constexpr Tile(value_type num = 0) noexcept : num_{num} {}

  [[nodiscard]] constexpr bool isEmpty() const noexcept { return num_ == 0; }

  [[nodiscard]] constexpr value_type value() const noexcept { return num_; }

  auto operator<=>(const Tile&) const = default;

private:
  value_type num_;
};

template <>
struct std::formatter<Tile> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

  auto format(const Tile& t, std::format_context& ctx) const {
    if (t.isEmpty())
      return std::format_to(ctx.out(), "    ");
    return std::format_to(ctx.out(), " {:>2} ", t.value());
  }
};
