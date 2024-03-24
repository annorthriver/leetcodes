#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // s[0, i - 1] = s[0, j - 1] + s[j, i - 1]
    // dp[i] = dp[j] && check[j, i - 1]
    // dp[0] = true; 空字符串总能分割
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> set(wordDict.begin(), wordDict.end());
      vector<bool> dp(s.size() + 1, false);
      dp[0] = true;
      for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
          if (dp[j] && set.find(s.substr(j, i - j)) != set.end()) {
            dp[i] = true;
            break;
          }
        }
      }
      return dp[s.size()];
    }
};

int main () {
  Solution s;
  string str = "leetcode";
  vector<string> words{"leet", "code"};
  auto res = s.wordBreak(str, words);
  std::cout << "res: " << res << std::endl;
}