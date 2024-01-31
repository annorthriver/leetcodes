#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 循环遍历，超出时间限制
int maxProfit_(vector<int>& prices) {
  int maxBenefit = 0;
  int size = prices.size();
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      int curBenefit = prices[j] - prices[i];
      if (curBenefit > 0 && curBenefit > maxBenefit) {
        maxBenefit = curBenefit;
      }
    }
  }
  return maxBenefit;
}

//维护左侧最小值
int maxProfit(vector<int>& prices) {
  int maxBenefit = 0;
  int minPrice = prices[0];
  int size = prices.size();
  for (int i = 1; i < size; i++) {
    maxBenefit = std::max(maxBenefit, prices[i] - minPrice);
    minPrice = std::min(minPrice, prices[i]);
  }
  return maxBenefit;
}

int main()
{
   std::vector<int> nums{7,1,5,3,6,4};
   int len = maxProfit(nums);
   cout << "num:" << len;
   return 0;
}