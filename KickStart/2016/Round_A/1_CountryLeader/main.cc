// #include <glog/logging.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>

int main(/* int argc, char const *argv[] */) {
  // FLAGS_log_dir =
  //     "/home/hub/GoogleCodingChallenges/KickStart/2016/"
  //     "Round_A/1_CountryLeader/log/";
  // google::InitGoogleLogging("CountryLeader");
  // auto input =
  // std::ifstream("KickStart/2016/Round_A/1_CountryLeader/test.txt");
  auto &input = std::cin;
  size_t ncase;
  input >> ncase;
  // LOG(INFO) << "number of cases: " << ncase;
  // LOG(INFO) << "######## STARTING LOOP ########";
  for (size_t tc = 0; tc < ncase; tc++) {
    size_t n_persons;
    input >> n_persons;
    // LOG(INFO) << "number of person for case #" << tc + 1 << ": " <<
    // n_persons;
    std::string s;
    std::getline(input, s);
    std::string leader;
    size_t leadersize = 0;
    for (size_t i = 0; i < n_persons; i++) {
      std::string name;
      std::getline(input, name);
      // LOG(INFO) << "name #" << i + 1 << ": " << name;
      std::set<char> letters;
      for (auto &&c : name)
        if (c != ' ') letters.insert(c);
      // LOG(INFO) << "number of different letters: " << letters.size();
      if (letters.size() > leadersize) {
        leader = name;
        leadersize = letters.size();
        // LOG(INFO) << "new leader with more letters: " << name;
      } else if (letters.size() == leadersize) {
        // LOG(INFO) << "same number of letters";
        if (name < leader) {
          // LOG(INFO) << name << "<" << leader << ": new leader: " << name;
          leader = name;
        } else {
          // LOG(INFO) << name << ">" << leader << ": no new leader.";
        }

      } else {
        // LOG(INFO) << name << " has less unique letters than " << leader;
      }
      // LOG(INFO) << "leader: " << leader;
    }
    std::cout << "Case #" << tc + 1 << ": " << leader << std::endl;
  }

  return 0;
}
