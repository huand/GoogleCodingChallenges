#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
// int ComputeScore(std::vector<int> value)

int main(/* int argc, char const* argv[] */) {
  size_t ncase;
  // std::ifstream input("test.txt");
  auto& input = std::cin;
  input >> ncase;
  for (size_t c = 0; c < ncase; c++) {
    size_t nsection;
    input >> nsection;
    std::vector<int> value(nsection);
    for (size_t i = 0; i < nsection; i++) {
      char ch;
      input >> ch;
      value[i] = ch - '0';
    }
    std::vector<int> integral_value(nsection + 1, 0);
    for (size_t i = 0; i < nsection; i++) {
      integral_value[i + 1] = integral_value[i] + value[i];
    }

    size_t wall_length = std::ceil(nsection / 2.);
    size_t nchoice = nsection - wall_length + 1;
    int bestscore = 0;
    for (size_t i = 0; i < nchoice; i++) {
      int currscore = integral_value[wall_length + i] - integral_value[i];
      if (currscore > bestscore) {
        bestscore = currscore;
      }
    }
    std::cout << "Case #" + std::to_string(c + 1) + ": " +
                     std::to_string(bestscore);
    if (c < ncase - 1) {
      std::cout << std::endl;
    }
  }

  return 0;
}
