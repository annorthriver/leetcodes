#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class TrieNode {
public:
    vector<TrieNode *> vec;
    bool isWord;
    TrieNode() : isWord(false), vec(26, nullptr) {
    }
    ~TrieNode() {
        for (auto *v : vec) {
           delete v;
        }
    }
};

class WordDictionary {
    TrieNode *root;
public:
    WordDictionary() {
      root = new TrieNode();
    }
    ~WordDictionary() {
        delete root;
    }

    void addWord(string word) {
      auto *p = root;
      for (auto c : word) {
        int idx = c - 'a'; 
        if (!p->vec[idx]) {
          p->vec[idx] = new TrieNode();
        }
        p = p->vec[idx];
      }
      p->isWord = true;
    }
    
    bool search(string word) {
      return dfs(word, root, 0);
    }
    bool dfs(string &word, TrieNode *p, int idx) {
      int len = word.size();
      if (len == idx) {
        return p->isWord;
      }
      auto c = word[idx];
      if (c == '.') {
        for (int i = 0; i < 26; i++) {
          if (p->vec[i] != nullptr && dfs(word, p->vec[i], idx + 1)) {
            return true;
          }
        }
      } else if (c >= 'a' && c <= 'z') {
        if (p->vec[c - 'a'] != nullptr && dfs(word, p->vec[c - 'a'], idx + 1)) {
          return true;
        }
      }
      return false;
    }
};

int main () {
  WordDictionary wordDictionary;
  wordDictionary.addWord("bad");
  wordDictionary.addWord("dad");
  wordDictionary.addWord("mad");
  std::cout << "res: " << wordDictionary.search("pad") << std::endl; // 返回 False
  std::cout << "res: " << wordDictionary.search("bad") << std::endl; // 返回 True
  std::cout << "res: " << wordDictionary.search(".ad") << std::endl; // 返回 True
  std::cout << "res: " << wordDictionary.search("b..") << std::endl; // 返回 True
  return 0;
}