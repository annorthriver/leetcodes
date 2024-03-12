#include <vector>
#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& res, int idx, int num, vector<int> &list,
             int &n, int &k) {
        list.push_back(idx);
        if (list.size() == k) {
            res.push_back(list);
            return;
        }
        for (int i = idx + 1; i <= n; i++) {
            dfs(res, i, num + 1, list, n, k);
            list.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        for (int i = 1; i <= n; i++) {
            vector<int> list;
            dfs(res, i, 0, list, n, k);
        }
        return res;
    }
};

int main () {
  Solution s;
  int n = 4, k = 2;
  auto res = s.combine(n, k);
  print(res);
  return 0;
}