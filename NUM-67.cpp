#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      int aLen = a.size();
      int bLen = b.size();
      while (aLen < bLen) {
        a = "0" + a;
        aLen++;
      }
      while (aLen > bLen) {
        b = "0" + b;
        bLen++;
      }
      int carry = 0;
      string res;
      for (int i = aLen - 1; i >= 0; i--) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        res.push_back(sum % 2 + '0');
        carry = sum / 2;
      }
      if (carry == 1) {
        res.push_back('1');
      }
      std::reverse(res.begin(), res.end());
      return res;
    }
};

int main() {
  string a("1010"), b("1011");
  Solution s;
  string res = s.addBinary(a, b);
  std::cout << "res: " << res << std::endl;
}