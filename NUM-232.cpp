#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
      while (!stack2.empty()) {
        stack1.push(stack2.top());
        stack2.pop();
      }
      stack1.push(x);
      while(!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    
    int pop() {
      int res = stack2.top();
      stack2.pop();
      return res;
    }
    
    int peek() {
      return stack2.top();
    }
    
    bool empty() {
      return stack2.empty();
    }
    std::stack<int> stack1;
    std::stack<int> stack2;
};

int main () {
  MyQueue myQueue = MyQueue();
  myQueue.push(1); // queue is: [1]
  myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
  int peekVal = myQueue.peek(); // return 1
  std::cout << "peekVal: " << peekVal << std::endl;
  int popVal = myQueue.pop(); // return 1, queue is [2]
  std::cout << "popVal: " << popVal << std::endl;
  if (myQueue.empty()) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;
}
