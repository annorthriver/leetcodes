#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最长回文子串

class Solution {
public:
    // 方法一：动态规划
    // 转移方程：dp[i][j] = dp[i+1][j-1] & s[i]==s[j]
    // dp数组表示当前i到j之间的字串是否为回文子串
    // 遍历顺序：外循环按照子串长度遍历，内循环遍历字符串
    // 注意，这个转移方程在长度是2的情况下不生效，因为i+1 j-1会导致i+1 < j -1，dp数组取到无效状态
    string longestPalindrome(string s) {
      int len = s.size();
      vector<vector<int>> dp(len, vector<int>(len, false));
      // i==j下，即长度为一的子串都是回文子串，对应dp数组的对角线
      for (int i = 0; i < len; i++) {
        dp[i][i]=true;
      }
      int maxLen = 1;
      int begin = 0;
      // 从长度2开始遍历,注意这里的<=，是需要遍历到字符串的长度
      for (int l = 2; l <= len; l++) {
        for (int i = 0; i < len; i++) {
          int j = i + l - 1;
          if (j >= len)
            break;
          if (s[i] != s[j]) {
            dp[i][j] = false;
          } else {
            if (l == 2) {
              dp[i][j] = true;
            } else {
              dp[i][j] = dp[i+1][j-1];
            }
          }
          if (dp[i][j] && maxLen < l) {
            maxLen = l;
            begin=i;
          }
        }
      }
      return s.substr(begin, maxLen);
    }

    // 方法2：中心扩展法
    // 从每一个位置出发，向两边扩散即可。遇到不是回文的时候结束
    // 向左或向右扩展，如果和当前字符相同，左或右边界扩展,+1
    // 左右同时扩展，判断左右字符是否相同，如果相同,+2
    // 否则，以下个字符为中心
    string longestPalindrome_(string s) {
    }
    // 方法3：Manacher算法
};

int main () {
  Solution s;
  std::string str{"cbbd"};
  auto res = s.longestPalindrome(str);
  std::cout << "str: " << res << std::endl;
}