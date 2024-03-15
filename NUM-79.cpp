#include <vector>
#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             const string& word, int index, int row, int col, int rows, int cols,
             string str) {
        if ((row < 0) || (row > rows - 1) || (col < 0) || (col > cols - 1) ||
            visited[row][col] || str.size() > word.size()) {
            return false;
        }
        if (board[row][col] != word[index]) {
          return false;
        }
        str += board[row][col];
        visited[row][col] = true;
        if (str == word) {
            return true;
        }
        bool res = dfs(board, visited, word, index + 1, row + 1, col, rows, cols, str);
        if (res) {
            return res;
        }
        res = dfs(board, visited, word, index + 1, row - 1, col, rows, cols, str);
        if (res) {
            return res;
        }
        res = dfs(board, visited, word, index + 1, row, col + 1, rows, cols, str);
        if (res) {
            return res;
        }
        res = dfs(board, visited, word,  index + 1,row, col - 1, rows, cols, str);
        if (res) {
            return res;
        }
        visited[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                string str;
                if (dfs(board, visited, word, 0, i, j, rows, cols, str)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main () {
  Solution s;
  vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  std::string word = "ABCCED";
  auto res = s.exist(board, word);
  std::cout << "res: " << res << std::endl;
  return 0;
}