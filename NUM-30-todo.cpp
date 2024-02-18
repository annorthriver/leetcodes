#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    
}

int main()
{
   std::string s{"barfoothefoobarman"};
   std::vector<std::string> words{"foo", "bar"};
   auto num = findSubstring(s, words);
   print(num);
   return 0;
}