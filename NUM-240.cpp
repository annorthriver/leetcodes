#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "utils.h"
using namespace std;

class Solution {
public:
    // 二分查找
    // 遍历每一行，使用二分查找
    // 剪枝策略：1. 如果每行第一个元素大于target，直接退出循环
    // 2.如果每行最后一个元素小于 target，跳过该行
    bool binarySearch(vector<int> &vec, int target) {
      int left = 0, right = vec.size() - 1;
      while (left <= right) {
        int middle = left + (right - left) / 2;
        if (vec[middle] < target) {
          left = middle + 1;
        } else if (vec[middle] > target) {
          right = middle - 1;
        } else {
          return true;
        }
      }
      return false;
    }
    bool searchMatrix_(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = matrix[0].size();
      if (m == 0 || n == 0) {
        return false;
      }
      for (int i = 0; i < m; i++) {
        // 如果当前行第一个数不是target，说明之前行没找到并且当前行及之后的行也不会有
        if (matrix[i][0] > target) {
          break;
        }
        // 当前行最后的数也比target小，跳过当前行搜索
        if (matrix[i][n - 1] < target) {
          continue;
        }
        if (binarySearch(matrix[i], target)) {
          return true;
        }
      }
      return false;
    }
    // 方法二：从右上角开始遍历，右上角元素，大于target，跳过当前列
    // 右上角元素小于target，跳过当前行
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = matrix[0].size();
      if (m == 0 || n == 0) {
        return false;
      }
      int row = 0, col = n - 1;
      while (row < m && col >= 0) {
        if (matrix[row][col] > target) {
          col--;
        } else if (matrix[row][col] < target) {
          row++;
        } else {
            return true;
        }
      }
      return false;
    }
};

int main () {
  Solution s;
  vector<vector<int>> grid = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  int target = 5;
  auto res = s.searchMatrix(grid, target);
  std::cout << "res: " << res << std::endl;
  return 0;
}