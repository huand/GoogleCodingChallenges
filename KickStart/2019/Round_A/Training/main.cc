#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

int main(/* int argc, char const* argv[] */) {
  //   std::ifstream in("test.txt");
  auto& in = std::cin;
  size_t ntest;
  in >> ntest;
  std::vector<unsigned long long> minhours(ntest);
  for (size_t ktest = 0; ktest < ntest; ktest++) {
    /* code */

    unsigned int n;
    unsigned int p;
    in >> n >> p;
    std::vector<unsigned long long int> s(n);
    for (size_t i = 0; i < n; i++) {
      in >> s[i];
    }
    std::sort(s.begin(), s.end());
    std::vector<unsigned long long> cummul_skill(s.size());
    cummul_skill[0] = s[0];
    for (size_t i = 1; i < s.size(); i++) {
      cummul_skill[i] = cummul_skill[i - 1] + s[i];
    }

    size_t nchoice = n - p + 1;
    std::vector<unsigned long long int> hours(nchoice);
    for (size_t i = 0; i < nchoice; i++) {
      if (i == 0) {
        hours[i] = s[p - 1 + i] * (p - 1) - (cummul_skill[i + p - 2] - 0ull);
      } else {
        hours[i] = s[p - 1 + i] * (p - 1) -
                   (cummul_skill[i + p - 2] - cummul_skill[i - 1]);
      }
    }
    minhours[ktest] = *std::min_element(hours.begin(), hours.end());
  }

  for (size_t i = 0; i < ntest; i++) {
    std::cout << "Case #" << i + 1 << ": " << minhours[i] << '\n';
  }

  return 0;
}
