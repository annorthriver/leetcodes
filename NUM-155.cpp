#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
      if (minStack.empty()) {
        minStack.push(val);
      } else {
        auto top = minStack.top();
        minStack.push(min(top, val));
      }
      stackInt.push(val);
    }
    
    void pop() {
      stackInt.pop();
      minStack.pop();
    }
    
    int top() {
      return stackInt.top(); 
    }
    
    int getMin() {
      return minStack.top();
    }
    stack<int> stackInt;
    stack<int> minStack;
};

int main () {
  MinStack s;
  s.push(-2);
  s.push(0);
  s.push(-3);
  auto res0 = s.getMin();
  std::cout << "res0: " << res0 << std::endl;
  s.pop();
  auto res1 = s.top();
  std::cout << "res1: " << res1 << std::endl;
  auto res2 = s.getMin();
  std::cout << "res2: " << res2 << std::endl;
}