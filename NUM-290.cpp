#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

bool wordPattern(string pattern, string s) {
  std::unordered_map<char, string> char2str;
  std::unordered_map<string, char> str2char;
  int strLen = s.size();
  int i = 0;
  for (auto c : pattern) {
    if (i >= strLen) {
      return false;
    }
    int j = i;
    while (j < strLen && s[j] != ' ') {
      j++;
    }
    auto subStr = s.substr(i, j - i);
    if (char2str.count(c) && char2str[c] != subStr) {
      return false;
    }
    if (str2char.count(subStr) && str2char[subStr] != c) {
      return false;
    }
    char2str[c] = subStr;
    str2char[subStr] = c;
    i = j + 1;
  }
  return i >= strLen;
}

int main()
{
   std::string pattern("aaaa"), s("dog cat cat dog");
   bool res = wordPattern(pattern, s);
   cout << "res: " << res;
   return 0;
}