#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

string reverseWords(string s) {
  int begin = 0, end = s.size() - 1;
  // 去掉前缀空格
  while(s.at(begin) == ' ') {
    begin++;
  }
  // 去掉后缀空格
  while(s.at(end) == ' ') {
    end--;
  }
  std::string res("");
  int rPos = end;
  while(end >= begin) {
   auto endChar = s.at(end);
   if (endChar == ' ') {
     if (end < rPos && s.at(end+1) != ' ') {
       res+=s.substr(end+1, rPos - end);
       rPos = end;
     }
     if (end >= begin && s.at(end - 1) != ' ') {
       res += std::string(" ");
       rPos = end - 1;
     }
   }
   end--;
  }
  if (rPos >= begin) {
    res+= s.substr(begin, rPos-begin+1);
  }
  return res;
}

int main()
{
   std::string strs("  the  sky is blue  ");
   std::string str = reverseWords(strs);
   cout << "str: " << str;
   return 0;
}