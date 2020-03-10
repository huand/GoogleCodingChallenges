#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

struct Pixel {
  int x;
  int y;
  Pixel operator+(const Pixel& p) { return Pixel{x + p.x, y + p.y}; }
};

struct Intervalle {
  int min;
  int max;
};

struct DataPix {
  std::vector<int> x;
  std::vector<int> y;
  std::vector<int> ind;
};

int main(/* int argc, char const* argv[] */) {
  std::string test_path =
      "/home/adlink/Documents/GoogleCodingChallenges/KickStart/2019/"
      "Round_A/Parcels/";
  std::ifstream input(test_path + "test.txt");
  std::cout << test_path + "test.txt" << std::endl;
  // auto& input = std::cin;
  size_t ncase{};
  input >> ncase;
  for (size_t icase = 0; icase < ncase; icase++) {
    size_t R{}, C{};
    std::vector<Pixel> vpix;
    std::vector<std::vector<int>> distance;
    {  // get instance problem input
      input >> R >> C;
      distance = std::vector<std::vector<int>>{R, std::vector<int>((int)C, -1)};
      for (size_t r = 0; r < R; r++) {
        for (size_t c = 0; c < C; c++) {
          char ch;
          input >> ch;
          if (ch == '1') {
            vpix.push_back({(int)c, (int)r});
            distance[r][c] = 0;
          }
        }
      }
    }
    // BFS
    std::vector<std::vector<Pixel>> dist_pix;
    std::queue<std::vector<Pixel>> qpix;
    qpix.push(vpix);
    dist_pix.push_back(vpix);
    std::vector<Pixel> dxdy{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dist = 0;
    while (!qpix.empty()) {
      dist++;
      auto vnode = qpix.front();
      qpix.pop();
      vpix.clear();
      for (auto& pix : vnode) {
        for (auto& dpix : dxdy) {
          auto child = pix + dpix;
          if (child.x >= 0 && child.y >= 0 && child.x < (int)C &&
              child.y < (int)R) {
            if (distance[child.y][child.x] == -1) {
              distance[child.y][child.x] = dist;
              vpix.push_back(child);
            }
          }
        }
      }
      if (!vpix.empty()) {
        qpix.push(vpix);
        dist_pix.push_back(vpix);
      }
    }
    // reformat data
    DataPix data;
    int d = 0;
    for (auto&& i : dist_pix) {
      data.ind.push_back(d);
      for (auto&& j : i) {
        d++;
        data.x.push_back(j.x);
        data.y.push_back(j.y);
      }
    }

    Intervalle K{0, (int)data.ind.size() - 1};
    while (K.max != K.min) {
      int candidate = (K.max + K.min) / 2;
      // Intervalle x, y;
      auto itxmin = std::min_element(data.x.begin() + data.ind[candidate + 1],
                                     data.x.end());
      auto itxmax = std::max_element(data.x.begin() + data.ind[candidate + 1],
                                     data.x.end());
      auto itymin = std::min_element(data.y.begin() + data.ind[candidate + 1],
                                     data.y.end());
      auto itymax = std::max_element(data.y.begin() + data.ind[candidate + 1],
                                     data.y.end());
      int CTopRig{(int)R}, CTopLef{(int)R + (int)C}, CBotRig{0},
          CBotLef{-(int)R - (int)C};

      for (int k = data.ind[candidate + 1]; k < (int)data.x.size(); k++) {
        auto& r = data.y[k];
        auto& c = data.x[k];
        auto C = r - c;
        CTopRig = CTopRig < C ? CTopRig : C;
        CBotLef = CBotLef > C ? CBotLef : C;
        C = r + c;
        CTopLef = CTopLef < C ? CTopLef : C;
        CBotRig = CBotRig > C ? CBotRig : C;
      }
      bool stop = false;
      for (int r = *itymin; r <= *itymax; r++) {
        for (int c = *itxmin; c <= *itxmax; c++) {
          auto d0 = r - c;
          auto d1 = r + c;
          auto dmax = std::max({abs(d0 - CTopRig), abs(d0 - CBotLef),
                                abs(d1 - CTopLef), abs(d1 - CBotRig)});
          if (dmax <= candidate) {
            K.max = candidate;
            stop = true;
            break;
          }
        }
        if (stop) {
          break;
        }
      }
      if (!stop) {
        K.min = candidate + 1;
      }
    }
    // std::cout << "Solution: " << K.min << std::endl;
    std::cout << "Case #" << icase + 1 << ": " << K.min << std::endl;
  }
  return 0;
}
