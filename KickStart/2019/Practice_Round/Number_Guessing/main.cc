#include <iostream>

struct Intervalle {
  size_t min = 0;
  size_t max = 0;
  size_t guess() const { return (max + min + 1) / 2; };
};

int main(/* int argc, char const *argv[] */) {
  size_t ncase;
  std::cin >> ncase;
  for (size_t icase = 0; icase < ncase; icase++) {
    Intervalle interv;
    std::cin >> interv.min;
    std::cin >> interv.max;
    size_t maxguess;
    std::cin >> maxguess;
    std::string answer;
    while (answer != "CORRECT" && maxguess--) {
      auto guess = interv.guess();
      std::cout << guess << std::endl;
      std::cin >> answer;
      if (answer == "TOO_BIG") {
        interv.max = guess - 1;
      } else if (answer == "TOO_SMALL") {
        interv.min = guess;
      }
    }
  }

  return 0;
}
