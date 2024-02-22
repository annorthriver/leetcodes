#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

// 将s, t映射到同一字符串，然后比较两者是否相同
bool isIsomorphic(string s, string t) {
  unordered_map<char, int> sMap, tMap;
  int sOrder = 0, tOrder = 0;
  int start = 'a';
  for (int i = 0; i < s.size(); i++) {
    if (sMap.count(s[i]) == 0) {
      sMap[s[i]] = sOrder;
      s[i] = 'a' + sOrder;
      sOrder++;
    } else {
      auto value = sMap[s[i]];
      s[i] = 'a' + value;
    }
    if (tMap.count(t[i]) == 0) {
      tMap[t[i]] = tOrder;
      t[i] = 'a' + tOrder;
      tOrder++;
    } else {
      auto value = tMap[t[i]];
      t[i] = 'a' + value;
    }  
  }
  return s == t;
}

// 另外的做法：不需要修改字符串，建立s2t和t2s的哈希表。

int main()
{
   std::string s("paper"), t("title");
   bool res = isIsomorphic(s, t);
   cout << "res: " << res;
   return 0;
}