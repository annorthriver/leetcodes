#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// 注意，这个题目的规律是行索引从0增大到numRows-1,然后再减少到0，然后按照每行的数输出
// 注意：初始step需要设置为-1，这样rowIdx=0时就可以正确设置为1了
string convert(string s, int numRows) {
  if (numRows < 2) {
    return s;
  }
  std::vector<std::string> res(numRows, "");
  int rowIdx = 0;
  int step = -1;
  for (int i = 0; i < s.size(); i++) {
    res[rowIdx].push_back(s.at(i));
    if (rowIdx == 0 || rowIdx == numRows - 1) {
      step = -step;
    }
    rowIdx += step;
  }
  std::string resStr("");
  for (auto str : res) {
    resStr += str;
  }
  return resStr;
}
// 方法二：利用二维矩阵模拟 一个周期是 numRows + numRows-2 个字符，
// 方法三：压缩矩阵空间
// 方法四：

int main()
{
   std::string strs("PAYPALISHIRING");
   int numRows = 3;
   std::string str = convert(strs, numRows);
   cout << "str: " << str;
   return 0;
}