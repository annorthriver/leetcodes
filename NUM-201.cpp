#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 会超时
    int rangeBitwiseAnd_(int left, int right) {
      int res = 0xFFFFFFFF;
      for (int i = left; i <= right; i++) {
        res &= i;
      }
      return res;
    }
    // 找到能使left和right相等的bit位，然后复原
    int rangeBitwiseAnd(int left, int right) {
      int zeros = 0;
      while (left < right) {
        zeros++;
        left >>= 1;
        right >>= 1;
      }
      return left << zeros;
    }
};

int main () {
  Solution s;
  int left = 5, right = 7;
  auto res = s.rangeBitwiseAnd(left, right);
  std::cout << "res: " << res << std::endl;
}