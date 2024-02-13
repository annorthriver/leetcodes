#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 有多种方法
// 1. 按行求
// 2. 按列求，每一个i都得到左边最高的墙和右边最高的墙
// 3. 动态规划，优化按列求左边最高的墙和右边最高的墙
// 4. 双指针法
// 5. 动态规划
//这里用动态规划
int trap(vector<int>& height) {
  auto size = height.size();
  std::vector<int> leftMax(size, 0);
  std::vector<int> rightMax(size, 0);
  for (int i = 1; i < size - 1; i++) {
    leftMax[i] = std::max(leftMax[i-1], height[i-1]);
  }
  for (int i = size - 2; i >= 0; i--) {
    rightMax[i] = std::max(rightMax[i+1], height[i+1]);
  }
  int sum = 0;
  for (int i = 1; i < size - 1; i++) {
    if (height[i] < leftMax[i] && height[i] < rightMax[i]) {
      sum += (std::min(leftMax[i], rightMax[i]) - height[i]);
    }
  }
  return sum;
}

int main()
{
   std::vector<int> height{4,2,0,3,2,5};
   int num = trap(height);
   cout << "num:" << num;
   return 0;
}