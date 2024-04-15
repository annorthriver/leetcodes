#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    bool isInclude(vector<int> &cntS, vector<int> &cntT) {
      for (int i = 'A'; i <= 'Z'; i++) {
        if (cntS[i] < cntT[i]) {
          return false;
        }
      }
      for (int i = 'a'; i <= 'z'; i++) {
        if (cntS[i] < cntT[i]) {
          return false;
        }
      }
      return true;
    }
public:
    string minWindow(string s, string t) {
      int len = s.size();
      int resLeft = -1, resRight = len, left = 0;
      vector<int> cntS(128, 0), cntT(128, 0);
      for (char c : t) {
        cntT[c]++;
      }
      for (int right = 0; right < len; right++) {
        cntS[s[right]]++;
        while (isInclude(cntS, cntT)) {
          if (right - left < resRight - resLeft) {
            resLeft = left;
            resRight = right;
          }
          cntS[s[left]]--;
          left++;
        }
      }
      return resLeft < 0 ? "" : s.substr(resLeft, resRight - resLeft + 1);
    }
    // 方法二：只用统计t中的字符有多少种，当区间内s对应字符出现的次数和t中相等时，统计的数量减一
};

int main () {
  Solution sol;
  std::string s("ADOBECODEBANC");
  std::string t("ABC");
  auto res = sol.minWindow(s, t);
  std::cout << "res: " << res << std::endl;
  return 0;
}