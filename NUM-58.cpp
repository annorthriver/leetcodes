#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// 反向遍历，得到最后一个单词的长度
int lengthOfLastWord(std::string s) {
   int end = s.size() - 1;
   while (s.at(end) == ' ') {
     end--;
   }
   int begin = end;
   while ((begin >= 0) && (s.at(begin) != ' ')) {
     begin--;
   }
   return end - begin;
}

int main()
{
   std::string s("Hello World  ");
   int len = lengthOfLastWord(s);
   std::cout << "len: " << len;
   return 0;
}