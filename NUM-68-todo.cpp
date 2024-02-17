#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {

}

int main()
{
   std::vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
   int maxWidth = 16;
   auto strs = fullJustify(words, maxWidth);
   for (auto str : strs) {
     cout << str << endl;
   }
   return 0;
}