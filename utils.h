#include <vector>

template <typename T>
void print(const std::vector<T>& container)
{
    for (T x : container)
        std::cout << x << ' ';
    std::cout << '\n';
}

template <typename T>
void print(const std::vector<std::vector<T>>& container)
{
    for (auto x : container)
        print(x);
}

template <typename T>
struct ListNode {
     T val;
     ListNode<T> *next;
     ListNode(T x) : val(x), next(NULL) {}
     ListNode() {}
};

template <typename T>
class ListCreater {
public:
  ListCreater(std::vector<T> in) : in_(in) {}
  ListNode<T> *createList() {
    if (in_.empty()) {
      return nullptr;
    }
    start = new struct ListNode<T>();
    auto *begin = start;
    for (auto iter = in_.begin(); iter != in_.end(); iter++) {
      begin->val = *iter;
      if (iter != in_.end() - 1) {
        begin->next = new struct ListNode<T>();
        begin = begin->next;
      } else {
        begin->next = nullptr;
      }
    }
    end = begin;
  }
  void createCycle(int pos) {
    int count = 0;
    while (auto begin = start->next) {
      if (pos == count) {
        end->next = 
      }

    }
  }

  ~ListCreater() {
    if (start) {
      if (start && start == end) {
        delete start;
        return;
      }
      struct ListNode<T> *curNode = start;
      struct ListNode<T> *nextNode = start->next ? start->next : nullptr;
      while(curNode) {
        delete curNode;
        curNode = nextNode;
        if (curNode && curNode == end) {
          break;
        }
        if (curNode && curNode->next) {
          nextNode = curNode->next;
        }
      }
    }
  }
private:
  std::vector<T> in_;
  ListNode<T> *start = nullptr;
  ListNode<T> *end = nullptr;
};