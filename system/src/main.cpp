#include <iostream>
#include <sibyl/sibyl.hpp>

int main() {
  std::cout << sibyl::add(1, 2) << "\n";
  std::cout << sibyl::subtract(1, 2) << "\n";
  sibyl::log();
  return 0;
}
