#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include "utils.h"
using namespace std;

// class Solution {
// public:
//     // 方法一：回溯法+string拼接
//     // 方法二：回溯法+Trie搜索(更少的无效搜索)
//     class TrieNode {
//     public:
//       string s;
//       vector<TrieNode *> vec;
//       TrieNode() : s(""), vec(26, nullptr) {}
//       ~TrieNode() {
//           for (auto *v : vec) {
//              delete v;
//           }
//       }
//     };
//     void insert(string word) {
//       TrieNode *p = root;
//       for (auto c : word) {
//         int idx = c - 'a';
//         if (!p->vec[idx]) {
//           p->vec[idx] = new TrieNode();
//         }
//         p = p->vec[idx];
//       }
//       p->s = word;
//     }
//     TrieNode *root = new TrieNode();
//     unordered_set<string> resSet;
//     vector<vector<int>> dirs{{-1, 0},{1, 0},{0, -1},{0, 1}};
//     int m = 0, n = 0;
//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//       m = board.size(), n = board[0].size();
//       vector<vector<bool>> visited(m, vector<bool>(n, false));
//       for (auto &word : words) {
//         insert(word);
//       }
//       for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             dfs(i, j, root, board, visited);
//         }
//       }
//       return vector<string>(resSet.begin(), resSet.end());
//     }
//     void dfs(int row, int col, TrieNode *p, vector<vector<char>>& board, vector<vector<bool>> &visited) {
//       if (row < 0 || row >= m || col < 0 || col >= n) {
//         return;
//       }
//       int cur = board[row][col] - 'a';
//       if (!p->vec[cur]) {
//         return;
//       }

//       if (!p->s.empty()) {
//         resSet.emplace(p->s);
//         // 可能还有可行解，所以不能用 return
//       }
//       visited[row][col] = true;
//       for (auto dir : dirs) {
//         int i = row + dir[0], j = col + dir[1];
//         dfs(i, j, p->vec[cur], board, visited); 
//       }
//       visited[row][col] = false;   
//     }
// };

class Solution {
public:
    // 方法一：回溯法+string拼接
    // 方法二：回溯法+Trie搜索(更少的无效搜索)
    class TrieNode {
    public:
      string s;
      vector<TrieNode *> vec;
      TrieNode() : s(""), vec(26, nullptr) {}
      ~TrieNode() {
          for (auto *v : vec) {
             delete v;
          }
      }
    };
    void insert(TrieNode *root, string word) {
      TrieNode *p = root;
      for (auto c : word) {
        int idx = c - 'a';
        if (!p->vec[idx]) {
          p->vec[idx] = new TrieNode();
        }
        p = p->vec[idx];
      }
      p->s = word;
    }
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root, unordered_set<string> & res) {
        char ch = board[x][y] - 'a';        
        if (!root->vec[ch]) {
            return false;
        }
        root = root->vec[ch];
        if (root->s.size() > 0) {
            res.insert(root->s);
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root,res);
                }
            }
        }
        board[x][y] = ch + 'a';

        return true;      
    }

    vector<string> findWords(vector<vector<char>> & board, vector<string> & words) {
        TrieNode * root = new TrieNode();
        unordered_set<string> res;
        vector<string> ans;

        for (auto & word: words){
            insert(root,word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }        
        for (auto & word: res) {
            ans.emplace_back(word);
        }
        return ans;        
    }
};

int main () {
  Solution sol;
  vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
  vector<string> words = {"oath","pea","eat","rain"};
  auto res = sol.findWords(board, words);
  print(res);
  return 0;
}