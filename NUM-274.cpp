#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int> &citations)
{
  std::sort(citations.begin(), citations.end(), std::greater<>());
  int h = 0;
  for (int i = 0; i < citations.size(); i++)
  {
    int curCit = citations[i];
    if (i + 1 <= curCit)
    {
      h++;
    }
    else
    {
      break;
    }
  }
  return h;
}

int main()
{
  std::vector<int> citations{100};
  int num = hIndex(citations);
  cout << "num:" << num;
  return 0;
}