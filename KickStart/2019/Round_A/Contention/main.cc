#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

struct Intervalle {
  size_t l;
  size_t r;
  size_t id;
  bool intree = false;
};

struct Node {
  size_t center;
  std::vector<size_t> i_center_left;
  std::vector<size_t> i_center_right;
  size_t node_left = 0;
  size_t node_right = 0;
  bool leaf = false;
};

int main(/* int argc, char const* argv[] */) {
  std::ifstream input("KickStart/2019/Round_A/Contention/test.txt");
  size_t T;
  input >> T;
  for (size_t tt = 0; tt < T; tt++) {
    // Load input
    size_t N, Q;
    input >> N >> Q;
    std::vector<Intervalle> intervalle(Q, {0, 0, 0});
    size_t lmin = N, rmax = 0;
    for (size_t i = 0; i < Q; i++) {
      input >> intervalle[i].l >> intervalle[i].r;
      intervalle[i].id = i;
      lmin = lmin < intervalle[i].l ? lmin : intervalle[i].l;
      rmax = rmax > intervalle[i].r ? rmax : intervalle[i].r;
    }
    // Build intervalle tree
    std::vector<Node> tree;
    tree.reserve(Q);
    while (true /*   */) {
      size_t mid = (lmin + rmax) / 2;
      std::vector<Intervalle> i_center;
      for (size_t i = 0; i < Q; i++) {
        if (intervalle[i].intree == false && intervalle[i].l <= mid &&
            intervalle[i].r >= mid) {
          i_center.push_back(intervalle[i]);
          intervalle[i].intree = true;
        }
      }
      auto i_center_l = i_center;
      std::sort(
          i_center_l.begin(), i_center_l.end(),
          [](const Intervalle& a, const Intervalle& b) { return a.l < b.l; });
      std::vector<size_t> ileft;
      for (auto&& i : i_center_l) {
        ileft.push_back(i.id);
      }

      auto i_center_r = i_center;
      std::sort(
          i_center_r.begin(), i_center_r.end(),
          [](const Intervalle& a, const Intervalle& b) { return a.r < b.r; });
      std::vector<size_t> iright;
      for (auto&& i : i_center_r) {
        iright.push_back(i.id);
      }
      tree.push_back({mid, ileft, iright});
    }
  }

  return 0;
}
