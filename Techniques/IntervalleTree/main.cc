#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

struct Intervalle {
  int l;
  int r;
};

struct IntervStack {
  std::list<Intervalle> intervalle;
  size_t idx_parent = 0;
  bool is_left = true;
};

struct Node {
  int xmid;
  std::list<Intervalle> mid_l;  // ordered from left
  // std::vector<size_t> l2r;      // mid_l[l2r[i]], ith smallest
  size_t id_node_L = 0;
  size_t id_node_R = 0;
};

int MidList(std::list<Intervalle> l) {
  auto min = std::min_element(
      l.begin(), l.end(),
      [](const Intervalle& a, const Intervalle& b) { return a.l < b.l; });
  auto max = std::max_element(
      l.begin(), l.end(),
      [](const Intervalle& a, const Intervalle& b) { return a.r < b.r; });
  return (min->l + max->r) / 2;
}

int main(/* int argc, char const* argv[] */) {
  auto inputpath = "Techniques/IntervalleTree/IntervalleTree.txt";
  std::ifstream input(inputpath);
  size_t n_itv;
  input >> n_itv;
  std::list<Intervalle> itv;
  for (size_t i = 0; i < n_itv; i++) {
    int l, r;
    input >> l >> r;
    itv.push_back({l, r});
  }

  std::vector<Node> tree;  //?
  // DFS
  std::stack<IntervStack> stack;  // todo: splice things up
  std::cout << itv.size() << " ";
  stack.push({std::move(itv), 0});
  std::cout << itv.size() << std::endl;
  while (!stack.empty()) {
    auto itvidx = stack.top();
    stack.pop();
    int xmid = MidList(itvidx.intervalle);
    Node node;
    node.xmid = xmid;

    std::list<Intervalle> listleft;
    std::list<Intervalle> listright;
    auto& itv = itvidx.intervalle;
    auto itvs = itv.size();
    for (size_t i = 0; i < itvs; i++) {  // while
      auto it = itv.begin();
      if (it->l <= xmid && it->r >= xmid) {
        node.mid_l.splice(node.mid_l.begin(), itv, it);
      } else if (it->r < xmid) {
        listleft.splice(listleft.begin(), itv, it);
      } else {
        listright.splice(listright.begin(), itv, it);
      }
    }
    tree.push_back(node);  //
    if (itvidx.is_left) {
      tree[itvidx.idx_parent].id_node_L = tree.size() - 1;
    } else {
      tree[itvidx.idx_parent].id_node_R = tree.size() - 1;
    }

    auto id_parent = tree.size() - 1;
    if (!listleft.empty()) {
      stack.push({std::move(listleft), id_parent, true});  //
    }
    if (!listright.empty()) {
      stack.push({std::move(listright), id_parent, false});  //
    }
  }

  Node node0 = Node();

  return 0;
}
