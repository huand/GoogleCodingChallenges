#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

struct Intervalle {
  int l;
  int r;
  size_t id;
};

// struct IntervalleTreeData {
//   Intervalle intervalle;
//   size_t id;
//   // bool in_tree = false;
// };

// struct Node{
//   int xmid;
//   std::vector<size_t> id_mid_l;  // ordered from left
//   std::vector<size_t> id_mid_r;  // ordered from right
//   size_t id_node_left;
//   size_t id_node_right;
// };

int main(/* int argc, char const* argv[] */) {
  auto inputpath = "Techniques/IntervalleTree/IntervalleTree.txt";
  std::ifstream input(inputpath);
  size_t n_intervalles;
  input >> n_intervalles;
  std::vector<Intervalle> intervalles(n_intervalles);
  for (size_t i = 0; i < n_intervalles; i++) {
    input >> intervalles[i].l >> intervalles[i].r;
    intervalles[i].id = i;
  }
  std::vector<size_t> intervalles_l;

  // std::vector<Node> tree;
  // DFS
  // std::stack<Node> stack_nodes;

  return 0;
}
