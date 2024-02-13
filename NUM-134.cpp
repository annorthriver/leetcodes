#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 思路：贪心的实现
// 1. sum(gas) < sum(cost), 一定无解
// 2. sum(gas) >= sum(cost), 一定有解
// 3. 如果从当前点出发到i点，剩余油量<0，就需要换起点到i+1点，从当前点到i+1点都不可能到达
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
  int remain = 0, start = 0, totalGas = 0, totalCost = 0;
  for (int i = 0; i < gas.size(); i++) {
    totalGas += gas[i];
    totalCost += cost[i];
    remain += (gas[i] - cost[i]);
    if (remain < 0) {
      start = i + 1;
      remain = 0;
    }
  }
  if (totalGas < totalCost) {
    return -1;
  }
  return start;
}

int main()
{
   std::vector<int> gas{2,3,4};
   std::vector<int> cost{3,4,3};
   int num = canCompleteCircuit(gas, cost);
   cout << "num:" << num;
   return 0;
}