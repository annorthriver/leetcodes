#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 需要满足两种规则：
// 1. 每个孩子一颗糖果
// 2. 当r[i] > r[i-1],i处糖果更多
// 3. 当r[i-1] < r[i], i-1处糖果更多
// 4. 取两次遍历最大值
int candy(vector<int>& ratings) {
    int size = ratings.size();
    std::vector<int> num(size, 1);
    for (int i = 1; i < size; i++) {
      if (ratings[i] > ratings[i-1]) {
        num[i] = num[i-1]+1;
      }
    }
    int total = num[size - 1];
    for (int i = size - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i+1]) {
        int tmp = num[i+1]+1;
        num[i] = std::max(tmp, num[i]);
      }
      total += num[i];
    }
    return total;
}

int main()
{
   std::vector<int> ratings{1,2,2};
   int num = candy(ratings);
   cout << "num:" << num;
   return 0;
}