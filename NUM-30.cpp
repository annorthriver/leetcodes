#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include "utils.h"
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int n = s.size(), m = words.size(), d = words[0].size();
    int len = m * d;
    unordered_map<string, int> str2int;
    // 统计当前words中的次数
    for (string w : words) {
      str2int[w]++;
    }
    // 需要有d - 1个起点，先判断起点是否满足要求
    vector<unordered_map<string, int>> vec(d);
    for (int i = 0; i < d && i + len <= n; i++) {
      for (int j = i; j < i + len; j+= d) {
        string w = s.substr(j, d);
        vec[i][w]++;
      }
      if (vec[i] == str2int) {
        res.push_back(i);
      }
    }
    // sliding window: 滑动窗口，每次移动d个位置
    for (int i = d; i + len <= n; i++) {
      int r = i % d;
      string left = s.substr(i - d, d), right = s.substr(i + len - d, d); 
      if (--vec[r][left] == 0) {
        vec[r].erase(left);
      }
      vec[r][right]++;
      if (vec[r] == str2int) {
        res.emplace_back(i);
      }
    }
    return res;
}

int main()
{
   std::string s{"barfoothefoobarman"};
   std::vector<std::string> words{"foo", "bar"};
   auto num = findSubstring(s, words);
   print(num);
   return 0;
}