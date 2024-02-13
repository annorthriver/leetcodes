#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最简单的循环遍历
int romanToInt(string s) {
  auto size = s.size();
  int dec = 0;
  for (int i = 0; i < size;) {
    if (s[i] == 'I') {
      if (s[i+1] == 'V') {
        i+=2;
        dec+=4;
        continue;
      }
      if (s[i+1] == 'X') {
        i+=2;
        dec+=9;
        continue;
      }
      dec+=1;
    }
    if (s[i] == 'V') {
      dec+=5;
    }
    if (s[i] == 'X') {
      if (s[i+1] == 'L') {
        i+=2;
        dec+=40;
        continue;
      }
      if (s[i+1] == 'C') {
        i+=2;
        dec+=90;
        continue;
      }
      dec+=10;      
    }
    if (s[i] == 'L') {
      dec+=50;
    }
    if (s[i] == 'C') {
      if (s[i+1] == 'D') {
        i+=2;
        dec+=400;
        continue;
      }
      if (s[i+1] == 'M') {
        i+=2;
        dec+=900;
        continue;
      }        
      dec+=100;
    }
    if (s[i] == 'D') {
      dec+=500;
    }
    if (s[i] == 'M') {
      dec+=1000;
    }
    i++;
  }
  return dec;
}
// 优化代码结构，通过使用map

int main()
{
   std::string str("MCMXCIV");
   int num = romanToInt(str);
   cout << "num:" << num;
   return 0;
}