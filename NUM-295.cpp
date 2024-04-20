#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
public:
    // 小根堆保存较大的一半数据，大根堆保存较小的一半数据，大小和大根堆多一或者相等
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQ;
    std::priority_queue<int, std::vector<int>, std::less<int>> maxQ;
    MedianFinder() {

    }
    
    void addNum(int num) {
      if (minQ.size() != maxQ.size()) {
        // minQ 比 maxQ大一，需要往maxQ插入，但是要先插入minQ，然后把minQ最小的数插入到maxQ
        minQ.push(num);
        maxQ.push(minQ.top());
        minQ.pop();
      } else {
        // minQ和maxQ相等，需要往minQ插入，但是先插入maxQ，然后把maxQ的最大的数插入到minQ
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();
      }
    }
    
    double findMedian() {
      if (minQ.size() != maxQ.size()) {
        return minQ.top();
      } else {
        return (minQ.top() + maxQ.top()) / 2.0;
      }
    }
};

int main()
{
   MedianFinder med;
   med.addNum(1);
   med.addNum(2);
   auto res = med.findMedian();
   std::cout << "res: " << res << std::endl;
   med.addNum(3);
   res = med.findMedian();
   std::cout << "res: " << res << std::endl;
   return 0;
}