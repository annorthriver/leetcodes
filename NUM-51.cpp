#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include "utils.h"

using namespace std;

class Solution {
public:
    unordered_set<int> cols, diag0, diag1;
    void dfs(vector<vector<string>> &res, vector<string> &sol, int row, int n) {
      if (row == n) {
        res.push_back(sol);
        return;
      }
      // 遍历所有列
      for (int i = 0; i < n; i++) {
        // 当前列不能有皇后
        if(cols.find(i) != cols.end()) {
          continue;
        }
        // 当前西北东南对角线不能有皇后，
        int negative = row - i;
        if (diag0.find(negative) != diag0.end()) {
          continue;
        }
        // 当前东北西南对角线不能有皇后
        int positive = row + i;
        if (diag1.find(positive) != diag1.end()) {
          continue;
        }
        cols.insert(i);
        diag0.insert(negative);
        diag1.insert(positive);
        sol[row][i] = 'Q';
        dfs(res, sol, row + 1, n);
        sol[row][i] = '.';
        cols.erase(i);
        diag0.erase(negative);
        diag1.erase(positive);
      }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> res;
      vector<string> sol(n, string(n, '.'));
      dfs(res, sol, 0, n);
      return res;
    }
};

int main () {
  Solution s;
  int n = 4;
  auto res = s.solveNQueens(n);
  print(res);
  return 0;
}