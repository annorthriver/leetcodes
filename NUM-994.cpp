#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 多源广度优先搜索
    int orangesRotting(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      queue<pair<int, int>> q;
      int fresh = 0;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j] == 1) {
            fresh++;
          } else if (grid[i][j] == 2) {
            q.push({i, j});
          }
        }
      }
      int minTime = -1;
      vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
      while(!q.empty()) {
        minTime++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
          auto cur = q.front();
          q.pop();
          for (auto &dir : dirs) {
            int x = cur.first + dir[0];
            int y = cur.second + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2 || grid[x][y] == 0) {
              continue;
            }
            fresh--;
            grid[x][y] = 2;
            q.push({x,y});
          }
        }
      }
      return fresh ? -1 : max(minTime, 0);
    }
};

int main () {
  Solution s;
  vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
  auto res = s.orangesRotting(grid);
  std::cout << "res: " << res << std::endl;
  return 0;
}