#pragma once

#include <iostream>
#include <ostream>
#include <string_view>

namespace wkw::output {
struct Highlight {
  std::string_view text;
};

inline std::ostream& operator<<(std::ostream& os, Highlight h) {
  return os << "\033[1;31m" << h.text << "\033[0m"; // bold red
}

template <typename T>
void print(const T& x, std::string_view prefix = "You entered") {
  std::cout << prefix << ": " << x << '\n';
}
} // namespace wkw::output
