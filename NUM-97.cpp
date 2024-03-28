#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 看作是路径规划题
    // row是s1, col是s2，s3是s1和s2构成的矩阵中的路径
    // dp[i][j] 表示s1前i个字符和col的前j个字符是否能构成s3
    // dp[m+1][n+1]
    // 边界：i== 0，s3的前j个必须由s2构成，否则为false
    // j == 0, s3的前i个必须由s1构成，否则为false
    // 状态转移：dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1])

    bool isInterleave(string s1, string s2, string s3) {
      int row = s1.size();
      int col = s2.size();
      if (row + col != s3.size()) {
        return false;
      }
      vector<vector<int>> dp(row+1, vector<int>(col+1, false));
      dp[0][0] = true;
      for (int i = 1; i <= row && (s1[i-1] == s3[i-1]); i++) {
        dp[i][0]=true;
      }
      for (int j = 1; j <= col && (s2[j-1] == s3[j-1]); j++) {
        dp[0][j]=true;
      }
      for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
          dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
        }
      }
      return dp[row][col];
    }
};

int main () {
  Solution s;
  std::string str1{"aabcc"},str2{"dbbca"},str3{"aadbbcbcac"};
  auto res = s.isInterleave(str1, str2, str3);
  std::cout << "res: " << res << std::endl;
}