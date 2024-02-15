#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// 方法一：横向比较
string longestCommonPrefix(vector<string>& strs) {
  int num = strs.size();
  string prefix = strs[0];
  for (int i = 1; i < num; i++) {
    auto curStr = strs[i];
    auto minSize = std::min(prefix.size(), curStr.size());
    int index = 0;
    // 找到最后相同的位置,使用索引，再做cut
    for (int m = 0; m < minSize; m++) {
      if (prefix[m] == curStr[m]) {
        index++;
      } else {
        break;
      }
    }
    prefix = prefix.substr(0, index);
  }
  return prefix;
}
// 方法二：纵向扫描，关键条件：到最小str的大小或者char不相等
// 方法三：递归分治
// 方法四：二分查找，可以将时间复杂度从mn减少到O(mn logm)

int main()
{
   std::vector<string> strs{"flower","flow","flight"};
   std::string str = longestCommonPrefix(strs);
   cout << "str: " << str;
   return 0;
}