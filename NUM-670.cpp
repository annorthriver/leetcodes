#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSwap(int num) {
  if (num >= 0 && num < 10) return num;
  int rem = num;
  int res = num;
  std::vector<int> nums;
  while(res != 0) {
    rem = res % 10;
    res = res / 10;
	  nums.push_back(rem);
  }
  std::vector<int> sortNums = nums;
  std::reverse(nums.begin(), nums.end());
  std::sort(sortNums.begin(), sortNums.end(), std::greater<int>());
  for (int i = 0; i < nums.size(); i++) {
	if (sortNums[i] == nums[i]) {
	  if (i == nums.size() - 1) {
	    return num;
	  }
      continue;  
	}
	int posRight = 0, posLeft = i;
	for (int j = nums.size() - 1; j >= 0; --j) {
      if (nums[j] == sortNums[i]) {
        posRight = j;
        break;
      }
  }
	  int tmp = nums[posRight];
	  nums[posRight] = nums[posLeft];
	  nums[posLeft] = tmp;
    break;
  }

  int maxNum = nums[0] * 10 + nums[1];
  for(int i = 2; i < nums.size(); i++) {
    maxNum = maxNum * 10 + nums[i];
  }
  return maxNum;
}
int main()
{
   int maxNum = maximumSwap(98368);
   cout << "maximum num:" << maxNum;
   return 0;
}