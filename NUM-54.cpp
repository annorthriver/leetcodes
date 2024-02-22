#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

//确定好一次螺旋的边界值left, right, top, bottom, 然后按照从左到右，从上到下，从右到左，从下到上
//并且在这个过程中动态更新边界值
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  int left = 0, right = col - 1, top = 0, bottom = row - 1;
  vector<int> res;
  while (true) {
    // 从左到右
    for (int i = left; i <= right; i++) {
      res.push_back(matrix[top][i]);
    }
    // 更新top并确认是否合法
    if (++top > bottom) break;
    // 从上到下
    for (int i = top; i <= bottom; i++) {
      res.push_back(matrix[i][right]);
    }
    // 更新right并确认是否合法
    if (--right < left) break;
    // 从右到左
    for (int i = right; i >= left; i--) {
      res.push_back(matrix[bottom][i]);
    }
    // 更新bottom并确认合法
    if (--bottom < top) break;
    // 从下到上
    for (int i = bottom; i >= top; i--) {
      res.push_back(matrix[i][left]);
    }
    // 更新left并确认合法
    if (++left > right) break;
  }
  return res;
}

int main()
{
  vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
   auto res = spiralOrder(matrix);
   print(res);
   return 0;
}