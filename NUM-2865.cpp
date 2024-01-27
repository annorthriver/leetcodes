#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//注意，美丽塔中的山峰数组最大值并不唯一，因此不能先找最大值

// 方法一：枚举
long long maximumSumOfHeights(vector<int>& maxHeights) {
  long long maxSum = 0;
  int vecSize = maxHeights.size();
  for (int i = 0; i < vecSize; i++) {
    int cur = maxHeights[i];
    long long mayMaxSum = cur;
    for (int j = i - 1; j >= 0; j--) {
       cur = std::min(maxHeights[j], cur);
       mayMaxSum += cur;
    }
    cur = maxHeights[i];
    for (int j = i + 1; j < vecSize; j++) {
       cur = std::min(maxHeights[j], cur);
       mayMaxSum += cur;
    }
    maxSum = std::max(mayMaxSum, maxSum);
  }
  return maxSum;
}

// 方法二：单调栈 TODO

int main()
{
   std::vector<int> nums{1,5,2,5,6,4,6,3,4,5};
   long long maxNum = maximumSumOfHeights(nums);
   cout << "maximum num:" << maxNum;
   return 0;
}