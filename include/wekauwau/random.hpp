#pragma once

// Requires C++20 or newer.

#include <cassert>
#include <chrono>
#include <concepts>
#include <random>

namespace wkw::random {

inline std::mt19937 generate() {
  std::random_device rd{};
  std::seed_seq ss{static_cast<std::seed_seq::result_type>(
                       std::chrono::steady_clock::now().time_since_epoch().count()),
                   rd(),
                   rd(),
                   rd(),
                   rd(),
                   rd(),
                   rd(),
                   rd()};
  return std::mt19937{ss};
}

inline std::mt19937& get_mt() {
  thread_local std::mt19937 mt{generate()};
  return mt;
}

template <std::integral T>
T get(T min, T max) noexcept {
  assert(min <= max);
  return std::uniform_int_distribution<T>{min, max}(get_mt());
}

template <std::integral R, std::integral S, std::integral T>
R get(S min, T max) noexcept {
  return get<R>(static_cast<R>(min), static_cast<R>(max));
}

template <std::floating_point T>
T get(T min, T max) noexcept {
  assert(min <= max);
  return std::uniform_real_distribution<T>{min, max}(get_mt());
}

} // namespace wkw::random
