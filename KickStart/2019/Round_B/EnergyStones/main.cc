#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

struct Stone {
  size_t s;
  size_t e;
  size_t l;
  bool operator<(const Stone& other) {
    std::cout << s << " " << l << " -- " << other.s << " " << other.l << '='
              << (s * other.l < other.s * l) << std::endl;
    return s * other.l < other.s * l;
  }
};

int main() {
  auto input = std::ifstream("KickStart/2019/Round_B/EnergyStones/test.txt");
  size_t ncase;
  input >> ncase;
  for (size_t tt = 0; tt < ncase; tt++) {
    size_t nstones;
    input >> nstones;
    std::vector<Stone> stones(nstones);
    for (size_t i = 0; i < nstones; i++) {
      input >> stones[i].s >> stones[i].e >> stones[i].l;
    }
    std::sort(stones.begin(), stones.end());
  }

  

  return 0;
}
