#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 经典拓扑排序的题
    // 通过拓扑排序判断课程安排图是否有环
    // 建立入度表和adjencent表(当前节点->后续节点的列表)，然后从入度为0的点开始遍历
    // 对该点的后续节点进行入度--
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> indgree(numCourses, 0);
      for (auto &pre : prerequisites) {
        indgree[pre[0]]++;
      }
      vector<vector<int>> adjencent(numCourses, vector<int>());
      // 将节点的后续user放到adjencent表
      for (auto &pre : prerequisites) {
        adjencent[pre[1]].push_back(pre[0]);
      }
      std:queue<int> q;
      for (int i = 0; i < numCourses; i++) {
        if (indgree[i] == 0) {
          q.push(i);
        }
      }
      int visited = 0;
      while (!q.empty()) {
        visited++;
        auto cur = q.front();
        q.pop();
        for (auto &user : adjencent[cur]) {
          --indgree[user];
          if (indgree[user] == 0) {
            q.push(user);
          }
        }
      }
      return visited == numCourses;
    }
};

int main () {
  Solution s;
  int numCourses = 2;
  vector<vector<int>> prerequisites{{1,0},{0,1}};
  auto res = s.canFinish(numCourses, prerequisites);
  std::cout << "res: " << res << std::endl;
}