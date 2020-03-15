#include <fstream>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <list>

struct Intervalle {
  int l;
  int r;
  size_t id;  //?
};

// struct IntervalleTreeData {
//   Intervalle intervalle;
//   size_t id;
//   // bool in_tree = false;
// };

struct Node {
  int xmid;
  std::list<Intervalle> mid_l;  // ordered from left
  std::vector<size_t> l2r;      // mid_l[l2r[i]], ith smallest
  size_t id_node_left;
  size_t id_node_right;
};

int main(/* int argc, char const* argv[] */) {
  auto inputpath = "Techniques/IntervalleTree/IntervalleTree.txt";
  std::ifstream input(inputpath);
  size_t n_itv;
  input >> n_itv;
  std::list<Intervalle> itv;
  for (size_t i = 0; i < n_itv; i++) {
    int l, r;
    input >> l >> r;
    itv.push_back({l, r, i});
  }

  std::vector<Node> tree;  //?
  // DFS
  std::stack<std::list<Intervalle>> stack;
  stack.push(itv);
  while (!stack.empty()) {
    auto list_itv = stack.top();
    stack.pop();
    auto min = std::min_element(
        list_itv.begin(), list_itv.end(),
        [](const Intervalle& a, const Intervalle& b) { return a.l < b.l; });
    auto max = std::max_element(
        list_itv.begin(), list_itv.end(),
        [](const Intervalle& a, const Intervalle& b) { return a.r > b.r; });

    int xmid = (min->l + max->r) / 2;
    Node node;
    node.xmid = xmid;
    for (auto&& i : list_itv) {
      if (i.l <= xmid && i.r >= xmid) {
        node.mid_l.splice(node.mid_l.begin(), list_itv,
                          std::list<Intervalle>::const_iterator(i));
      }
    }
  }

  // std::vector<size_t> itvmid;
  // std::vector<size_t> itvl;
  // std::vector<size_t> itvr;
  // for (auto&& i : itv) {
  //   if (i.l <= xmid && i.r >= xmid) {
  //     itvmid.push_back(i.id);
  //   } else if (i.r < xmid) {
  //     itv_l.push_back(i.id);
  //   } else {
  //     itv_r.push_back(i.id);
  //   }
  // }

  Node node0 = Node();

  return 0;
}
