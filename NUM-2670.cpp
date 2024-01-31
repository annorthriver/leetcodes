#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

void print(const std::vector<int>& container)
{
    for (const int x : container)
        std::cout << x << ' ';
    std::cout << '\n';
}

//哈希set, 这种方式空间占用大
vector<int> distinctDifferenceArray(vector<int>& nums) {
   std::vector<int> res;
   for (int i = 0; i < nums.size(); i++) {
      std::unordered_set<int> prefix(nums.begin(), nums.begin()+i+1);
      std::unordered_set<int> postfix(nums.begin()+i+1, nums.end());
      res.push_back(prefix.size() - postfix.size());
   }
   return res;
}

// 方法二：循环外使用set, 从最后一个数往前遍历数组，存入后缀数据到set，统计数量
//   然后清空set, 再从前往后遍历数组，与存入的后缀数组位置+1做减法


// 方法三：位运算 https://leetcode.cn/problems/find-the-distinct-difference-array/solutions/2626011/wei-yun-suan-kuai-su-qiu-bu-tong-yuan-su-79yk/

int main()
{
   std::vector<int> nums{3,2,3,4,2};
   std::vector<int> res = distinctDifferenceArray(nums);
   print(res);
   return 0;
}