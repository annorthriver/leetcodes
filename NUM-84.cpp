#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 方法一：暴力法
    // 方法二：单调栈法
    // 对于当前元素，当右边元素比它小时，右边界即可确定，左边界由单调栈的左边元素确定
    int largestRectangleArea(vector<int>& heights) {
      int len = heights.size();
      vector<int> newHeights(len+2, 0);
      stack<int> s;
      // 添加左右边界
      // 左边界是为了确定第一个数的左边界
      // 右边界是为了确定最后数组遍历完成后stack里所有数的右边界
      for (int i = 0; i < len; i++) {
        newHeights[i+1] = heights[i];
      }
      int area = 0;
      for (int i = 0; i < len + 2; i++) {
        while (!s.empty() && newHeights[s.top()] > newHeights[i]) {
          int curHeight = newHeights[s.top()];
          s.pop();
          int right = i; // 当前进入该条件的cur右边的第一个比cur小的就是i
          int left = s.top(); // pop cur后的stack top就是左边比cur小的数索引
          int width = right - left - 1;
          area = std::max(area, width * curHeight);
        }
        s.push(i);
      }
      return area;
    }
};

int main () {
  Solution s;
  vector<int> vec{2,4};
  auto res = s.largestRectangleArea(vec);
  std::cout << "res: " << res << std::endl;
}