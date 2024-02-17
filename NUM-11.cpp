#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
  int left = 0, right = height.size() - 1;
  int max = -1;
  while (left < right) {
    int curArea = (right - left) * (std::min(height[left], height[right]));
    if (curArea > max) {
      max = curArea;
    }
    if (height[left] <= height[right]) { left++; }
    else {right--;}
  }
  return max;
}

int main()
{
   std::vector<int> nums{1,8,6,2,5,4,8,3,7};
   auto max = maxArea(nums);
   cout << "max: " << max;
   return 0;
}