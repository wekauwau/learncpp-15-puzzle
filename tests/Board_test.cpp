#include "Board.hpp"
#include "Direction.hpp"
#include "Point.hpp"
#include "Tile.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Default Board", "[Board]") {
  auto result = Board::create();
  REQUIRE(result);
  if (!result)
    return;

  Board& b = *result;
  REQUIRE(b.size.height == 4);
  REQUIRE(b.size.width == 4);
  REQUIRE(b.size.size == 16);
  REQUIRE(b.getEmptyTile() == Point{3, 3});

  REQUIRE_FALSE(b.slide(Direction{Direction::Type::Up}));
  REQUIRE(b.getEmptyTile() == Point{3, 3});
  REQUIRE(*b[b.getEmptyTile()] == Tile{});

  REQUIRE_FALSE(b.slide(Direction{Direction::Type::Left}));
  REQUIRE(b.getEmptyTile() == Point{3, 3});
  REQUIRE(*b[b.getEmptyTile()] == Tile{});

  REQUIRE(b.slide(Direction{Direction::Type::Down}));
  REQUIRE(b.getEmptyTile() == Point{2, 3});
  REQUIRE(*b[b.getEmptyTile()] == Tile{});
  REQUIRE(b.getLastMovedTile() == Point{3, 3});
  REQUIRE(*b[b.getLastMovedTile()] == Tile{12});

  REQUIRE(b.slide(Direction{Direction::Type::Right}));
  REQUIRE(b.getEmptyTile() == Point{2, 2});
  REQUIRE(*b[b.getEmptyTile()] == Tile{});
  REQUIRE(b.getLastMovedTile() == Point{2, 3});
  REQUIRE(*b[b.getLastMovedTile()] == Tile{11});
}

TEST_CASE("5x7 Board", "[Board]") {
  auto result = Board::create(5, 7);
  REQUIRE(result);
  if (!result)
    return;

  Board& b = *result;
  REQUIRE(b.size.height == 7);
  REQUIRE(b.size.width == 5);
  REQUIRE(b.size.size == 35);
  REQUIRE(b.getEmptyTile() == Point{6, 4});

  REQUIRE_FALSE(b.slide(Direction{Direction::Type::Up}));
  REQUIRE(b.getEmptyTile() == Point{6, 4});
  REQUIRE(*b[b.getEmptyTile()] == Tile{});

  REQUIRE_FALSE(b.slide(Direction{Direction::Type::Left}));
  REQUIRE(b.getEmptyTile() == Point{6, 4});
  REQUIRE(*b[b.getEmptyTile()] == Tile{});

  REQUIRE(b.slide(Direction{Direction::Type::Down}));
  REQUIRE(b.getEmptyTile() == Point{5, 4});
  REQUIRE(*b[b.getEmptyTile()] == Tile{});
  REQUIRE(b.getLastMovedTile() == Point{6, 4});
  REQUIRE(*b[b.getLastMovedTile()] == Tile{30});

  REQUIRE(b.slide(Direction{Direction::Type::Right}));
  REQUIRE(b.getEmptyTile() == Point{5, 3});
  REQUIRE(*b[b.getEmptyTile()] == Tile{});
  REQUIRE(b.getLastMovedTile() == Point{5, 4});
  REQUIRE(*b[b.getLastMovedTile()] == Tile{29});
}

TEST_CASE("Win condition and shuffle", "[Board]") {
  auto result = Board::create();
  REQUIRE(result);
  if (!result)
    return;

  Board& b = *result;
  REQUIRE(b.isSolved());

  // Anchor the timeline
  constexpr int n = 1000;
  std::vector<Direction> moves{};
  moves.reserve(n);            // avoids reallocation
  for (int i{0}; i < n; ++i) { // shuffle the board...
    auto d = Direction::random();
    if (b.slide(d))
      moves.push_back(d);
  }
  REQUIRE_FALSE(b.isSolved());

  // Going back in time
  for (auto it = moves.rbegin(); it != moves.rend(); ++it)
    b.slide(-(*it));
  REQUIRE(b.isSolved());
}
