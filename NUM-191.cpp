#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int num = 0;
        for (int i = 0; i < 32; i++) {
          if (n & (1 << i)) {
            num++;
          }
        }
        return num;
    }
    int hammingWeight_(int n) {
        int num = 0;
        while (n) {
            n &= n - 1;
            num++;
        }
        return num;
    }
};

int main () {
  Solution s;
  auto res = s.hammingWeight_(128);
  std::cout << "res: " << res << std::endl;
}