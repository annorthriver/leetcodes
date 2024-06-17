#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 第一步：构图，将所有变量之间的路径权值计算出来（包括正向反向）
    // 第二步：查询
    // 两种方法：广度优先搜索，Floyd算法
    // 这里是Floyd算法
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      int num = 0;
      unordered_map<string, int> str2num;

      int size = equations.size();
      for (int i = 0; i < size; i++) {
        if (str2num.find(equations[i][0]) == str2num.end()) {
          str2num[equations[i][0]] = num++; 
        }
        if (str2num.find(equations[i][1]) == str2num.end()) {
          str2num[equations[i][1]] = num++; 
        }
      }
      vector<vector<double>> graph(num, vector<double>(num, -1));
      for (int i = 0; i < size; i++) {
        int num1 = str2num[equations[i][0]], num2 = str2num[equations[i][1]];
        graph[num1][num2] = values[i];
        graph[num2][num1] = 1 / values[i];
      }
      // Floyd算法
      for (int k = 0; k < num; k++) {
        for (int i = 0; i < num; i++) {
          for (int j = 0; j < num; j++) {
            if (graph[i][j] > 0)
              continue;
            // 注意这里可能会有精度问题
            if (graph[i][k] > 1e-6 && graph[k][j] > 1e-6) {
              graph[i][j] = graph[i][k] * graph[k][j];
            }
          }
        }
      }
      // 查询
      vector<double> res;
      for (auto &query : queries) {
        if (str2num.find(query[0]) == str2num.end() || str2num.find(query[1]) == str2num.end()) {
          res.push_back(-1);
          continue;
        }
        int num1 = str2num[query[0]], num2 = str2num[query[1]];
        res.push_back(graph[num1][num2]);
      }
      return res;
    }
};

int main () {
  Solution s;
  vector<vector<string>> equations{{"a","b"},{"b","c"}};
  vector<double> values{2.0, 3.0};
  vector<vector<string>> queries{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
  auto res = s.calcEquation(equations, values, queries);
  print(res);
}