#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s) {
      int i = 0, j = s.size() - 1;
      while (i < j) {
        if (s[i] != s[j]) {
          return false;
        }
        i++;
        j--;
      }
      return true;
    }
    void dfs(vector<vector<string>> &res, vector<string> &vec, string &s, int i) {
      if (i == s.size()) {
        res.push_back(vec);
        return;
      }
      for (int j = i; j < s.size(); j++) {
        string subStr = s.substr(i, j - i + 1);
        if(isPalindrome(subStr)) {
          vec.push_back(subStr);
          dfs(res, vec, s, j + 1);
          vec.pop_back();
        }
      }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      vector<string> str;
      dfs(res, str, s, 0);
      return res; 
    }
};

int main () {
  Solution s;
  string str = "aab";
  auto res = s.partition(str);
  print(res);
  return 0;
}