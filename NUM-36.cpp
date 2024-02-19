#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool isValidSudoku(vector<string> &board) {
    int row[9][9] = {0}, col[9][9] = {0}, subBlock[3][3][9] = {0};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.')
                continue;
            int num = board[i][j] - '0' - 1;
            row[i][num]++;
            col[j][num]++;
            subBlock[i / 3][j / 3][num]++;
            if (row[i][num] > 1 || col[j][num] > 1 ||
                subBlock[i / 3][j / 3][num] > 1) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
  vector<string> board = {{"53..7...."},
   {"6..195..."},
   {".98....6."},
   {"8...6...3"},
   {"4..8.3..1"},
   {"7...2...6"},
   {".6....28."},
   {"...419..5"},
   {"....8..79"}};
   bool res = isValidSudoku(board);
   cout << "res: " << res;
   return 0;
}