#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
      int m = heightMap.size(), n = heightMap[0].size();
      if (m <= 2 || n <= 2) {
        return 0;
      }
      // x, y, maxHeight
      using point = std::tuple<int, int, int>;
      auto cmp = [](point x, point y) {return std::get<2>(x) > std::get<2>(y); };
      // 建立小根堆，每次从高度最小（木桶原理）的点开始更新周边
      std::priority_queue<point, vector<point>, decltype(cmp)> q(cmp);
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      // 将边缘作为起始的遍历点
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (i == 0 || i == m - 1 || j == 0 || j ==  n - 1) {
            q.push({i, j, heightMap[i][j]});
            visited[i][j] = true;
          }
        }
      }
      int ans = 0;
      vector<vector<int>> dirs{{1, 0},{-1, 0},{0, 1},{0, -1}};
      // 每次取当前q里maxHeight最小的点扩散（通过小根堆保证）
      while(!q.empty()) {
        auto curPoint = q.top();
        q.pop();
        int x = std::get<0>(curPoint);
        int y = std::get<1>(curPoint);
        int curHeight = std::get<2>(curPoint);
        for (auto &dir : dirs) {
          int dx = x + dir[0];
          int dy = y + dir[1];
          if (dx < 0 || dx >= m || dy < 0 || dy >= n || visited[dx][dy]) {
            continue;
          }
          if (curHeight > heightMap[dx][dy]) {
            ans += curHeight - heightMap[dx][dy];
          }
          q.push({dx, dy, std::max(curHeight, heightMap[dx][dy])});
          visited[dx][dy] = true;
        }
      }
      return ans;
    }
};

int main () {
  Solution s;
  vector<vector<int>> heightMap{{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
  auto res = s.trapRainWater(heightMap);
  std::cout << "res: " << res << std::endl;
}