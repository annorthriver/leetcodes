#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include "utils.h"
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  std::unordered_map<string, std::vector<string>> str2str;
  for (auto &str : strs) {
    auto cStr = str;
    std::sort(cStr.begin(), cStr.end());
    str2str[cStr].push_back(str);
  }
  vector<vector<string>> res;
  for (const auto &[key, value] : str2str) {
    res.push_back(value);
  }
  return res;
}

int main()
{
   vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
   auto res = groupAnagrams(strs);
   print(res);
   return 0;
}