#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

// 遍历为0的点，然后将横竖刷为0，并且使用reset做标记
// 空间使用较多(O(m*n))
void setZeroes(vector<vector<int>>& matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  vector<vector<bool>> reset(row, vector<bool>(col, false));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (matrix[i][j] == 0 && !reset[i][j]) {
        for (int k = 0; k < row; k++) {
          if (matrix[k][j] && !reset[k][j]) {
            matrix[k][j] = 0;
            reset[k][j] = true;
          }
        }
        for (int k = 0; k < col; k++) {
          if (matrix[i][k] && !reset[i][k]) {
            matrix[i][k] = 0;
            reset[i][k] = true;
          }
        }
      }
    }
  }  
}

// 方法二：使用row(m), col(n)即可

// 方法三：使用第一行和第一列存储是否要刷本行本列

int main()
{
  //vector<vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
  vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
   setZeroes(matrix);
   print(matrix);
   return 0;
}