#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// 双指针一：
bool isPalindrome(string s) {
  string str;
  for (int i = 0; i < s.size(); i++) {
    if (std::isalnum(s[i])) {
      str.push_back(std::tolower(s[i]));
    }
  }
  int size = str.size();
  int forward = 0, backward = size - 1;
  while (forward < backward) {
    if (str[forward] != str[backward]) {
      return false;
    }
    forward++;
    backward--;
  }
  return true;
}
// 双指针二：直接在原字符串上做判断，left < right

int main()
{
   std::string str("0P");
   bool res = isPalindrome(str);
   cout << "res:" << res;
   return 0;
}