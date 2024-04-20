#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      vector<pair<int, int>> projects;
      for (int i = 0; i < profits.size(); i++) {
        projects.push_back({capital[i], profits[i]});
      }
      std::sort(projects.begin(), projects.end(), [](auto &a, auto &b){return a.first < b.first;});
      // 大根堆
      std::priority_queue<int, vector<int>, less<int>> q;
      int cur = 0;
      while (k > 0) {
        // 在当前资本w下可以做的所有的项目，构建大根堆
        while(cur < projects.size() && projects[cur].first <= w) {
          q.push(projects[cur++].second);
        }
        // k很大的情况下，项目可能已经做完了
        if (q.empty()) {
          break;
        }
        // 取收益最大的项目
        w += q.top();
        // 将这个项目pop出去
        q.pop();
        // 已经做完一个项目，减去这个项目数
        k--;
      }
      return w;
    }
};

int main()
{
   Solution s;
   int k = 2, w = 0;
   std::vector<int> profits{1,2,3};
   std::vector<int> capital{0,1,1};
   int res = s.findMaximizedCapital(k, w, profits, capital);
   std::cout << "res: " << res << std::endl;
   return 0;
}