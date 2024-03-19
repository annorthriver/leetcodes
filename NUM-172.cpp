#include <iostream>

class Solution {
public:
    // 计算尾随0的数量，5x2的数量，本质是5的数量(每隔两个数出现一个2，每隔五个数出现一个5，所以5一定会有个2与之配对)
    // 5x1...5x2...5x3...5x4...5x5x1...5x6...(每隔25个数出现两个5，每隔125个数出现三个5)
    // 因此尾随0的数量是n/5(一个5的数量)+n/25(两个5的数量)+n/125(三个5的数量)
    int trailingZeroes_(int n) {
      int num = 0;
      while (n > 0) {
        n = n / 5;
        num += n;
      }
      return num;
    }
    // 递归解法
    int trailingZeroes(int n) {
      if (n < 5) return 0;
      n /= 5;
      return n + trailingZeroes(n);
    }
};

int main() {
  Solution s;
  int in = 25;
  auto res = s.trailingZeroes(in);
  std::cout << "res: " << res << std::endl;
}