#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;
    TrieNode() : isWord(false), children(26, nullptr) {
    }
    ~TrieNode() {
        for (auto& c : children)
            delete c;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
      root = new TrieNode();
    }
    ~Trie() {
      delete root;       
    }
    
    void insert(string word) {
      TrieNode *p = root;
      for (char c : word) {
        int idx = c -'a';
        if (!p->children[idx]) {
          p->children[idx] = new TrieNode();
        }
        p = p->children[idx];
      }
      p->isWord = true;
    }
    
    bool search(string word) {
      TrieNode* p = root;
      for (char c : word) {
        int idx = c - 'a';
        if (!p->children[idx])
          return false;
        p = p->children[idx];
      }
      return p->isWord;
    }
    
    bool startsWith(string prefix) {
      TrieNode* p = root;
      for (char c : prefix) {
        int idx = c - 'a';
        if (!p->children[idx])
          return false;
        p = p->children[idx];
      }
      return true;
    }
};

int main () {
  Trie t;
  t.insert("apple");
  t.search("apple");
  t.search("app");
  t.startsWith("app");
  t.insert("app");
  t.search("app");
}