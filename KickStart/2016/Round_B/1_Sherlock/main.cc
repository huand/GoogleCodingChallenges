#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>

struct Params {
  size_t L, R;
};

template <typename T>
auto ReadCaseInput(T& ifs) {
  Params p;
  ifs >> p.L >> p.R;
  return p;
}

size_t SolveCase(const Params& p) {
  auto e = std::min({p.L, p.R});
  return e * (e + 1) / 2;
}

template <typename T>
void PrintResult(size_t n, T res) {
  std::cout << "Case #" << n << ": " << res << std::endl;
}

template <typename T>
void ProcessCase(T& ifs, const size_t& tc) {
  auto lr = ReadCaseInput(ifs);
  auto n = SolveCase(lr);
  PrintResult(tc + 1, n);
}

template <typename T>
void ProcessAll(T& ifs) {
  size_t ncase;
  ifs >> ncase;
  for (size_t tc = 0; tc < ncase; tc++) {
    ProcessCase(ifs, tc);
  }
}

int main(/* int argc, char const *argv[] */) {
  // auto input = std::ifstream("KickStart/2016/Round_B/1_Sherlock/test.txt");
  auto& input = std::cin;
  ProcessAll(input);

  return 0;
}
