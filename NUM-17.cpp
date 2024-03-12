#include <vector>
#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

class Solution {
public:
    vector<string> letters{"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(vector<string>& res, string& digits, int idx, string s) {
        if (idx == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[idx] - '0';
        for (auto c : letters[digit]) {
            dfs(res, digits, idx + 1, s + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> res;
        dfs(res, digits, 0, "");
        return res;
    }
};

int main () {
  Solution s;
  string digits = "23";
  auto res = s.letterCombinations(digits);
  print(res);
}