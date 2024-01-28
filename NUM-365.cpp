#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

//这里从一个状态出发会得到六个状态，然后下个状态仍然如此，因此是对图每个状态节点的搜索
// 直到节点满足要求
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
  if ((jug1Capacity == 0) || (jug2Capacity == 0)) {
    return targetCapacity == (jug1Capacity + jug2Capacity);
  }
  if (targetCapacity > jug1Capacity + jug2Capacity) {
    return false;
  }
  // remainX, remainY
  using Status = std::pair<int, int>;
  std::queue<Status> states;
  std::set<Status> visited;
  states.push(std::make_pair(0, 0));
  while (!states.empty()) {
    auto curState = states.front();
    if (visited.count(curState)) {
      states.pop();
      continue;
    }
    visited.insert(curState);
    auto [remainX, remainY] = curState;
    states.pop();
    if (remainX == targetCapacity || remainY == targetCapacity ||
        remainX + remainY == targetCapacity) {
      return true;
    }
    states.push(std::make_pair(0, remainY));
    states.push(std::make_pair(remainX, 0));
    states.push(std::make_pair(jug1Capacity, remainY));
    states.push(std::make_pair(remainX, jug2Capacity));
    states.push(std::make_pair(remainX-std::min(jug2Capacity - remainY, remainX), remainY+min(jug2Capacity - remainY, remainX)));
    states.push(std::make_pair(remainX+std::min(jug1Capacity-remainX, remainY), remainY - std::min(jug1Capacity-remainX, remainY)));
  }

  return false;
}
// 方法二：数学原理，贝祖定理，ax+by = z

int main()
{
   bool can = canMeasureWater(1,2,3);
   cout << "status:" << can;
   return 0;
}
