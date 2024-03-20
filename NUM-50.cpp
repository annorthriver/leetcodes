#include <iostream>
#include <cmath>

class Solution {
public:
    //快速幂（二进制理解）
    // x^(n)   n-> 1*b1+2*b2+4*b3+8*b4 
    double myPow(double x, int n) {
      if (x == 0.0f) return 0.0;
      long p = n;
      double res = 1;
      if (n < 0) {
        x = 1 / x;
        p = -p;
      }
      while (p > 0) {
        if (p & 1) {
          res *= x;
        }
        x *= x;
        p >>= 1;
      }
      return res;
    }
};

int main() {
  Solution s;
  double x = 2;
  int n = 4;
  auto res = s.myPow(x, n);
  std::cout << "res: " << res << std::endl;
}