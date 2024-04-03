#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 异或本质上累加每个比特位后每个比特位做模2运算
    // 本题是每个比特位累加后做模3运算
    int singleNumber(vector<int>& nums) {
      int ans = 0;
      for (int i = 0; i < 32; i++) {
        int count = 0;
        for (auto &num : nums) {
            count += (num >> i & 1);
        }
        ans |= (count % 3) << i;
      }
      return ans;
    }
};

int main () {
  Solution s;
  vector<int> nums{2, 2, 3, 2};
  auto res = s.singleNumber(nums);
  std::cout << "pos: " << res << std::endl;
}