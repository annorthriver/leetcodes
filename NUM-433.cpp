#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>
#include "utils.h"
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
      unordered_set<string> bankSet(bank.begin(), bank.end());
      queue<string> q;
      unordered_set<string> visited;
      q.push(startGene);
      int step = 0;
      while (!q.empty()) {
        auto curSize = q.size();
        // 因为是求最少变化次数，因此按层遍历，如果当前层有状态先到终点，
        // 即为最少移动次数
        for (int i = 0; i < curSize; i++) {
          auto cur = q.front();
          q.pop();
          if (cur == endGene) return step;
          for (char c : "ACGT") {
            for (int j = 0; j < startGene.size(); j++) {
                auto newStr = cur;
                newStr[j] = c;
                if (!visited.count(newStr) && bankSet.count(newStr)) {
                  q.push(newStr);
                  visited.insert(newStr);
                }
            }
          }
        }
        // 每层步骤加一
        step++;
      }
      return -1;
    }
};

int main () {
  Solution s;
  string start{{"AACCGGTT"}};
  string end{"AAACGGTA"};
  vector<string> bank{{"AACCGGTA","AACCGCTA","AAACGGTA"}};
  auto res = s.minMutation(start, end, bank);
  std::cout << "res: " << res << std::endl;
}