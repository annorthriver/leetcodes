#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const std::vector<int>& container)
{
    for (const int x : container)
        std::cout << x << ' ';
    std::cout << '\n';
}

std::vector<int> productExceptSelf(std::vector<int>& nums) {
  auto size = nums.size();
  std::vector<int> ans(size, 1);
  int init = 1;
  // 计算下三角矩阵的结果
  for (int i = 1; i < size; i++) {
    ans[i] =  ans[i - 1] * nums[i - 1];
  }
  // 计算上三角矩阵的结果并累乘到ans里
  int tmp = 1;
  for (int i = size - 2; i >= 0; i--) {
    tmp *= nums[i+1];
    ans[i] *= tmp; 
  }
  return ans;
}

int main()
{
   std::vector<int> nums{-1,1,0,-3,3};
   auto res = productExceptSelf(nums);
   print(res);
   return 0;
}