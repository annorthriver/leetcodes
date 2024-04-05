#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 返回课程学习的顺序，对有向无环图的拓扑排序
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> indegree(numCourses, 0);
      vector<vector<int>> users(numCourses, vector<int>());

      for (auto &pre : prerequisites) {
        indegree[pre[0]]++;
      }
      for (auto &pre : prerequisites) {
        users[pre[1]].push_back(pre[0]);
      }
      std::queue<int> q;
      for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
          q.push(i);
        }
      }
      vector<int> res;

      while (!q.empty()) {
        auto cur = q.front();
        res.push_back(cur);
        q.pop();
        for (auto &user : users[cur]) {
          --indegree[user];
          if (indegree[user] == 0) {
            q.push(user);
          }
        }
      }
      // 判断是否有环，如果有环，返回空数组
      if (res.size() != numCourses) {
        return {};
      }
      return res;
    }
};

int main () {
  Solution s;
  int numCourses = 4;
  vector<vector<int>> prerequisites{{1,0},{2,0},{3,1},{3,2}};
  auto res = s.findOrder(numCourses, prerequisites);
  print(res);
}