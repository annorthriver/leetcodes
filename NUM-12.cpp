#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// 1. 寻找不超过num的最大的符号值，使用pair存储
// pair必须按照从大到小排列
std::string intToRoman(int num) {
std::vector<std::pair<int, std::string>> intToStr = {
         {1000, "M"},
         {900, "CM"},
         {500, "D"},
         {400, "CD"},
         {100, "C"},
         {90, "XC"},
         {50, "L"},
         {40, "XL"},
         {10, "X"},
         {9, "IX"},
         {5, "V"},
         {4, "IV"},
         {1, "I"}
         };
  std::string roman("");
  for (auto &[value, symbol] : intToStr) {
    while (num >= value) {
      num -= value;
      roman += symbol;
    }
    if (num == 0) {
      break;
    }
  }
  return roman;
}

// 2.硬编码查表，个、十、百、千分别列出所有对应的表示，然后通过除法和取模查表

int main()
{
   int num = 1994;
   std::string str = intToRoman(num);
   cout << "str: " << str;
   return 0;
}