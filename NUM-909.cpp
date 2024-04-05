#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 将当前的index映射到实际的row和col上，并获取board上对应
    // 的状态
    int getNext(int idx, vector<vector<int>>& board) {
      int n = board.size();
      // 反向 row状态
      int row = (idx - 1) / n;
      // col根据row状态确定是反向还是正向
      int col = (idx - 1) % n;
      // 如果反向row是奇数，col是反向，需要转正向
      // 如果反向row是偶数，col就是正向
      if (row % 2 == 1) {
        col = n - 1 - col;
      }
      // 反向row变成正向，获取状态
      if (board[n - 1 - row][col] != -1) {
        return board[n - 1 - row][col];
      }
      return idx;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
      int n = board.size();
      int step = 0;
      vector<bool> visited(n * n + 1, false);
      std::queue<int> q;
      // 从1开始
      q.push(1);
      while (!q.empty()) {
        int curSize = q.size();
        // 遍历当前的队列，获取当前所有状态的下一状态
        for (int i = 0; i < curSize; i++) {
          auto cur = q.front();
          q.pop();
          if (cur == n * n) {
            return step;
          }
          for (int j = 1; j <= 6; j++) {
            int next = cur + j;
            if (next > n * n) {
              break;
            }
            int mayJump = getNext(next, board);
            if (!visited[mayJump]) {
              q.push(mayJump);
              visited[mayJump] = true;
            }
          }
        }
        step++;
      }
      return -1;
    }
};

int main () {
  Solution s;
  int numCourses = 4;
  vector<vector<int>> board{{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},
  {-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
  auto res = s.snakesAndLadders(board);
  std::cout << "res: " << res << std::endl;
}