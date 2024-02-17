#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// 双指针
bool isSubsequence(string s, string t) {
  int tPtr = 0, sPtr = 0;
  while (sPtr < s.size()) {
    auto cur = s[sPtr];
    while (tPtr < t.size() && cur != t[tPtr]) {
      tPtr++;
    }
    if (sPtr < s.size() && tPtr == t.size()) {
      return false;
    }
    sPtr++;
    tPtr++;
  }
  return true;
}
// 动态规划

int main()
{
   std::string s("aaaaaa"), t("bbaaaa");
   bool res = isSubsequence(s, t);
   cout << "res:" << res;
   return 0;
}