#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include "utils.h"

using namespace std;

class Solution {
public:
    unordered_set<int> cols, diag1, diag2;
    int dfs(int n, int row) {
      if (row == n) {
        return 1;
      }
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (cols.find(i) != cols.end()) {
          continue;
        }
        int positive = row - i;
        if (diag1.find(positive) != diag1.end()) {
          continue;
        }
        int negative = row + i;
        if (diag2.find(negative) != diag2.end()) {
          continue;
        }
        cols.emplace(i);
        diag1.emplace(positive);
        diag2.emplace(negative);
        count += dfs(n, row + 1);
        cols.erase(i);
        diag1.erase(positive);
        diag2.erase(negative);
      }
      return count;
    }
    int totalNQueens(int n) {
      return dfs(n, 0);
    }
};

int main () {
  Solution s;
  int n = 4;
  auto res = s.totalNQueens(n);
  std::cout << "num: " << res << std::endl;
  return 0;
}