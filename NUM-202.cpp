#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_set>
using namespace std;

int getNext(int n) {
  int sum = 0;
  while (n > 0) {
    int tmp = n % 10;
    sum += tmp * tmp;
    n = n / 10;
  }
  return sum;
}

// 两种状态： 1. 最终到1，是快乐数 2.是一个循环，不是快乐数 3.很大的数最终都会降到3维一下，回到1，2的状态
// 使用哈希表
bool isHappy(int n) {
  std::unordered_set<int> set;
  int sum = getNext(n);
  while (sum != 1 && !set.count(sum)) {
    set.emplace(sum);
    sum = getNext(sum);
  }
  return sum == 1;
}

// 快慢指针：判断循环的方法
bool isHappy_(int n) {
  int slow = n, fast = n;
  do {
    slow = getNext(slow);
    fast = getNext(getNext(fast));
  } while (slow != fast);
  return slow == 1;
}

int main()
{
   int n = 19;
   auto num = isHappy(n);
   std::cout << "ret: " << num << endl;
   return 0;
}