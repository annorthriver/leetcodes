#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = matrix_new;
}

int main()
{
  vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
   rotate(matrix);
   print(matrix);
   return 0;
}