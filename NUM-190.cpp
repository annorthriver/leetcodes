#include <iostream>
#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t res = 0;
      for (int i = 0; i < 32; i++) {
        res = (res << 1) | (n & 1);
        n >>= 1;
      }
      return res;
    }
};

int main () {
  Solution s;
  uint32_t n = 0b00000010100101000001111010011100;
  uint32_t res = s.reverseBits(n);
  std::cout << "bits: " << res << std::endl;
}