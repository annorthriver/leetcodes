#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

// 统计每个点的周围状态，然后再根据周围状态修改当前状态
void gameOfLife(vector<vector<int>>& board) {
  int row = board.size();
  int col = board[0].size();
  vector<vector<int>> status(row, vector<int>(col, 0));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int num = 0;
      if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1]) {
        num++;
      }
      if (i - 1 >= 0 && board[i - 1][j]) {
        num++;
      }
      if (j - 1 >= 0 && board[i][j - 1]) {
        num++;
      }
      if (i - 1 >= 0 && j + 1 < col && board[i - 1][j + 1]) {
        num++;
      }
      if (j + 1 < col && board[i][j + 1]) {
        num++;
      }
      if (i + 1 < row && j - 1 >= 0 && board[i + 1][j - 1]) {
        num++;
      }
      if (i + 1 < row && board[i + 1][j]) {
        num++;
      }
      if (i + 1 < row && j + 1 < col && board[i + 1][j + 1]) {
        num++;
      }
      status[i][j] = num;
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (board[i][j]) {
        if (status[i][j] < 2 || status[i][j] > 3) {
          board[i][j] = 0;
        }
      } else {
        if (status[i][j] == 3) {
          board[i][j] = 1;
        }
      }
    }
  }
}

// 优化代码： for循环遍历i j周围元素，使用索引数组
// 可以使用位运算优化，将状态挪到倒数第二位，然后右移倒数第二位bit到最后一位

int main()
{
  vector<vector<int>> board{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

   gameOfLife(board);
   print(board);
   return 0;
}