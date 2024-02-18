#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

// 滑动窗口
int lengthOfLongestSubstring(string s) {
  int len = s.size();
  int left = 0, right = 0, maxLen = 0;
  std::set<char> chars;
  for (; right < len; right++) {
    while (chars.count(s[right])) {
        chars.erase(s[left]);
        left++;
    }
    chars.emplace(s[right]);
    maxLen = std::max(maxLen, right - left + 1);
  }
  return maxLen;
}

int main()
{
   std::string str{"pwwkew"};
   int num = lengthOfLongestSubstring(str);
   cout << "num: " << num;
   return 0;
}