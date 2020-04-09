#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

struct Intervalle {
  size_t l;
  size_t r;
};

int main(/* int argc, char const *argv[] */) {
  std::ifstream input("KickStart/2019/Round_B/Palindromes/test.txt");
  // auto& input = std::cin;
  size_t ntest;
  input >> ntest;
  for (size_t tt = 0; tt < ntest; tt++) {
    size_t N, Q;
    input >> N >> Q;
    std::vector<char> letters(N, 'A');
    for (size_t i = 0; i < N; i++) {
      input >> letters[i];
    }

    std::vector<Intervalle> q(Q);
    for (size_t i = 0; i < Q; i++) {
      input >> q[i].l >> q[i].r;
    }

    std::vector<std::vector<size_t>> LetterCount(26,
                                                 std::vector<size_t>(N + 1, 0));
    for (size_t i = 0; i < N; i++) {
      for (size_t j = 0; j < 26; j++) {
        LetterCount[j][i + 1] = LetterCount[j][i];
      }

      auto l = letters[i] - 'A';
      LetterCount[l][i + 1]++;
    }

    size_t result = 0;
    for (size_t qq = 0; qq < Q; qq++) {
      std::vector<size_t> count(26, 0);
      for (size_t i = 0; i < 26; i++) {
        auto c = LetterCount[i][q[qq].r] - LetterCount[i][q[qq].l - 1];
        count[i] = c;
      }

      size_t nsolo = 0;
      for (size_t i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
          nsolo++;
          if (nsolo > 1) break;
        }
      }
      if (nsolo < 2) {
        result++;
      }
    }
    std::cout << "Case #" << tt + 1 << ": " << result << std::endl;
  }

  return 0;
}
