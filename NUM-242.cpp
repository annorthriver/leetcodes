#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

// 方法一：排序后两个字符串相等
bool isAnagram(string s, string t) {
  if (s.size() != t.size()) return false;
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());
  return s == t;
}

// 方法二：使用vector模拟哈希表
bool isAnagram_(string s, string t) {
  if (s.size() != t.size()) return false;
  std::vector<int> vec(26, 0);
  for (auto c : s) {
    vec[c - 'a']++;
  }
  for (auto c : t) {
    vec[c - 'a']--;
    if (vec[c - 'a'] < 0) {
      return false;
    }
  }
  return true;
}

int main()
{
   std::string s("anagra"), t("anagrm");
   bool res = isAnagram_(s, t);
   cout << "res: " << res;
   return 0;
}