#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>
#include "utils.h"
using namespace std;

class Solution {
public:
    string list{"abcdefghijklmnopqrstuvwxyz"};
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> wordSet(wordList.begin(), wordList.end());
      unordered_set<string> visited;
      queue<string> q;
      q.push(beginWord);
      int step = 0;
      while (!q.empty()) {
        int curSize = q.size();
        for (int i = 0; i < curSize; i++) {
            auto cur = q.front();
            q.pop();
            // 由于是返回最短转换序列的单词数目，因此需要++step
            if (cur == endWord) return ++step;
            for (char c = 'a'; c <= 'z'; c++) {
            // for (auto c : list) {
                for (int j = 0; j < beginWord.size(); j++) {
                    auto next = cur;
                    next[j] = c;
                    if (!visited.count(next) && wordSet.count(next)) {
                      q.push(next);
                      visited.insert(next);
                    }
                }
            }
        }
        step++;
      }
      return 0;
    }
};

int main () {
  Solution s;
  string start{{"hit"}};
  string end{"cog"};
  vector<string> bank{{"hot","dot","dog","lot","log","cog"}};
  auto res = s.ladderLength(start, end, bank);
  std::cout << "res: " << res << std::endl;
}