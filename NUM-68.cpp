#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> res;
  int num = words.size();
  vector<string> list;
  for (int i = 0; i < num; ) {
    // 当前list装当前的word
    list.clear();
    list.push_back(words[i]);
    int cur = words[i++].size();
    while (i < num && (cur + 1 + words[i].size() <= maxWidth)) {
      cur = cur + 1 + words[i].size();
      list.push_back(words[i++]);
    }
    // 如果当前是最后一行，左对齐
    if (i == num) {
      string str = list.front();
      for (int k = 1; k < list.size(); k++) {
        str += " ";
        str += list[k];
      }
      while (str.size() != maxWidth) {
        str += " ";
      } 
      res.push_back(str);
      break;
    }
    // 如果当前行只有一个单词，左对齐（在中间行占据了一行的单词）
    if (list.size() == 1) {
      string str = list.front();
      while (str.size() != maxWidth) {
        str += " ";
      }
      res.push_back(str);
      continue;
    }
    // 一般情况的处理
    int wordWidth = cur - (list.size() - 1); // 统计的单词空格的长度减去空格的数量
    int spaceWidth = maxWidth - wordWidth; // 本行总空格长度
    int perSpaceWidth = spaceWidth / (list.size() - 1); // 平均每个间隔的空格长度
    int remainSpaceNum = spaceWidth % (list.size() - 1); // 前面需要插入额外一个空格的间隔数
    string space(perSpaceWidth, ' ');
    string str;
    for (int k = 0; k < list.size(); k++) {
      str+=list[k];
      if (k == list.size() - 1) break;
      if (k < remainSpaceNum) {
        str += (space + " ");
      } else {
        str += space;
      }
    }
    res.push_back(str);
  }
  return res;
}

int main()
{
   // std::vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
   std::vector<string> words{"What","must","be","acknowledgment","shall","be"};
   int maxWidth = 16;
   auto strs = fullJustify(words, maxWidth);
   for (auto str : strs) {
     cout << str << endl;
   }
   return 0;
}