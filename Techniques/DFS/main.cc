// generating all permutation with a DFS

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

struct Node {
  size_t value;
  size_t level;
};

int main(/* int argc, char const* argv[] */) {
  size_t n = 1;
  while (n != 0) {
    std::cout << "Enter a number of elements to permute: (0 to quit)";
    std::cin >> n;

    std::vector<size_t> complete_set(n);
    for (size_t i = 0; i < n; i++) {
      complete_set[i] = i;
    }

    std::vector<size_t> v(n);
    std::stack<Node> s;
    for (size_t i = 0; i < n; i++) {
      s.push({i, 0});
    }
    size_t k = 0;
    while (!s.empty()) {
      Node node = s.top();
      s.pop();
      v[node.level] = node.value;
      if (node.level == n - 1) {
        for (auto&& i : v) {
          std::cout << i << ", ";
        }
        std::cout << "# permutation " << ++k << std::endl;
      } else {
        std::vector<Node> children(n - 1 - node.level);
        auto vs = v;  // slicing
        std::sort(vs.begin(), vs.begin() + 1 + node.level);
        std::vector<size_t> children_ind(n - 1 - node.level);
        std::set_difference(complete_set.begin(), complete_set.end(),
                            vs.begin(), vs.begin() + 1 + node.level,
                            children_ind.begin());
        for (auto&& child : children_ind) {
          s.push({child, node.level + 1});
        }
      }
    }
  }
  return 0;
}
