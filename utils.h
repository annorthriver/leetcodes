#include <vector>
#include <unordered_map>

template <typename T, typename S = int>
class Disjoint {
  private:
    std::unordered_map<T, T> parent;
    std::unordered_map<T, S> rank;
  public:
    Disjoint() = default;
    T find(T x) {
      if (parent.count(x) == 0) {
        return nullptr;
      }
      return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }
    void addElem(T elem) {
      if (parent.count(elem) != 0)
        return;
      parent[elem] = elem;
      rank[elem] = 0;
    }
    void toUnion(T x1, T x2) {
      T f1 = find(x1);
      T f2 = find(x2);
      if (rank[f1] > rank[f2]) {
        parent[f2] = f1;
      } else {
        parent[f1] = f2;
        if (rank[f1] == rank[f2])
          ++rank[f2];
      }
    }
    bool isSame(T x1, T x2) {
      return find(x1) == find(x2);
    }
    std::unordered_map<T, T> getNodeMap() {
      return parent;
    }
    void replace(T x, T elem) {
      parent[x] = elem;
    }
};

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
  ListNode() : val(0), next(nullptr) {}
  ListNode(T x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode<T> *next) : val(x), next(next) {}
};

template <typename T>
void printNonCycleList(ListNode<T> *head) {
  if (head) {
    struct ListNode<T> *curNode = head;
    int count = 0;
    while(curNode) {
      std::cout << "list[" << count << "]: " << curNode->val << std::endl;
      curNode = curNode->next;
      count++;
    }
  } else {
    std::cout << "List is empty!" << std::endl;
  }
}

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
    return start;
  }
  void createCycle(int pos) {
    if (start == end) {
      if (pos != 0) {
        std::cout << "Invalid pos!" << std::endl;
        return;
      }
      end->next = start;
      return;
    }
    struct ListNode<T> *curNode = start;
    struct ListNode<T> *nextNode = curNode->next ? curNode->next : nullptr;
    int count = 0;
    while(curNode != end) {
      if (count == pos) {
        end->next = curNode;
        return;
      }
      curNode = nextNode;
      nextNode = nextNode->next;
      count++;
    }
    if (count == pos) {
      end->next = end;
    }
  }
  void print() {
    if (start) {
      if (start == end) {
        std::cout << "list[0]: " << start->val << std::endl;
        return;
      }
      struct ListNode<T> *curNode = start;
      struct ListNode<T> *nextNode = curNode->next ? curNode->next : nullptr;
      int count = 0;
      while(curNode != end) {
        std::cout << "list[" << count << "]: " << curNode->val << std::endl;
        curNode = nextNode;
        nextNode = nextNode->next;
        count++;
      }
      std::cout << "list[" << count << "]: " << end->val << std::endl;
    } else {
      std::cout << "List is empty!" << std::endl;
    }
  }
  ~ListCreater() {
    if (start) {
      if (start == end) {
        delete start;
        return;
      }
      struct ListNode<T> *curNode = start;
      struct ListNode<T> *nextNode = curNode->next ? curNode->next : nullptr;
      while(curNode != end) {
        delete curNode;
        curNode = nextNode;
        nextNode = nextNode->next;
      }
      delete end;
    }
  }
private:
  std::vector<T> in_;
  ListNode<T> *start = nullptr;
  ListNode<T> *end = nullptr;
};