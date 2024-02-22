#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
  vector<int> count(26, 0);
  for (int i = 0; i < magazine.size(); i++) {
    count[magazine[i] - 'a']++;
  }
  for (int i = 0; i < ransomNote.size(); i++) {
    if (count[ransomNote[i] - 'a'] == 0) {
      return false;
    }
    count[ransomNote[i] - 'a']--;
  }
  return true;
}

int main()
{
   std::string ransomNote("aa"), magazine("aab");
   bool res = canConstruct(ransomNote, magazine);
   cout << "res: " << res;
   return 0;
}