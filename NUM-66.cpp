#include <iostream>
#include <vector>
#include "utils.h"
#include <algorithm>
using namespace std;

class Solution {
public:
    // Bad，在数很大的情况下会超出long表示范围
    vector<int> plusOne_(vector<int>& digits) {
      long num = 0;
      for (auto &digit : digits) {
        num = num * 10 + digit;
      }
      num++;
      digits.clear();
      while (num) {
        digits.emplace_back(num % 10);
        num /= 10;
      }
      std::reverse(digits.begin(), digits.end());
      return digits;
    }
    // 只要找到倒数第一个加一不进位的位置即可
    vector<int> plusOne(vector<int>& digits) {
      for (int i = digits.size() -1; i >= 0 ; i--) {
        digits[i] = (digits[i] + 1) % 10;
        if (digits[i] != 0) {
          return digits;
        }
      }
      digits.insert(digits.begin(), 1);
      return digits;
    }

};

int main() {
  Solution s;
  vector<int> in{1,2,3};
  auto res = s.plusOne(in);
  print(res);
}