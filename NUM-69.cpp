#include <iostream>
#include <cmath>

class Solution {
public:
    int mySqrt_(int x) {
      if (x == 0) {
        return 0;
      }
      if (x <= 3) {
        return 1;
      }
      int res = 0;
      for (int i = 3; i < x; i++) {
        int min = (i - 1) * (i - 1);
        int max = i * i;
        if (x >= min && x < max) {
          res = i - 1;
          break;
        }
      }
      return res;
    }
    // e^(0.5 * ln(x))
    // 二分查找
    // 牛顿迭代法
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (std::fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
    // 二进制计算
    int mySqrtBinary(int x) {
        int m = 0x40000000, y = 0, b = 0;

        while(m != 0){
            b = y ^ m;
            y = y >> 1;
            if(x >= b){
                x = x - b;
                y = y ^ m;
            }
            m = m >> 2;
        }
        return y;
    }
    // 内联汇编
    int mySqrtInline(int x){
      double s = x;
      __asm__ (
              "movq %1, %%xmm0;"
              "sqrtsd %%xmm0, %%xmm1;"
              "movq %%xmm1, %0"
              :"+r"(s)
              :"r"(s)
              );
      return s;
    }
};

int main() {
  Solution s;
  int in = 4;
  auto res = s.mySqrt(in);
  std::cout << "res: " << res << std::endl;
}