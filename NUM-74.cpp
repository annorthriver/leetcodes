#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 方法一：两次二分查找，会超出时间限制
    // 拉成一维查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            // int middle = (right + left) / 2;
            // 上述写法可能会有溢出的问题，写成如下的实现
            int middle = left + (right - left) / 2;
            int x = matrix[middle / n][middle % n];
            if (x > target) {
                right = middle - 1;
            } else if (x < target) {
                left = middle + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main () {
  Solution s;
  int target = 3;
  vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
  //vector<vector<int>> matrix{{1},{3},{5}};
  auto res = s.searchMatrix(matrix, target);
  std::cout << "min dis: " << res << std::endl;
}