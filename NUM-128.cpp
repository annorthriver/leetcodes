#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 哈希表去重，然后维护最大长度，注意起始点跳过无效遍历，即curNum-1不在哈希表里
int longestConsecutive_(vector<int>& nums) {
  std::unordered_set<int> numSet;
  for (const auto &num : nums) {
    numSet.emplace(num); 
  }
  int maxLen = 0;
  for (auto num : numSet) {
    if (!numSet.count(num - 1)) {
      int nextNum = num + 1;
      int len = 1;
      while (numSet.count(nextNum)) {
        len++;
        nextNum++;
      }
      maxLen = std::max(maxLen, len);
    }
  }
  return maxLen;
}

// 方法二：并查集
template <typename T, typename S = int>
class Disjoint {
  private:
    std::unordered_map<T, T> parent;
    std::unordered_map<T, S> rank;
    int count = 0;
  public:
    Disjoint() = default;
    T find(T x) {
      return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }
    void addElem(T elem) {
      if (parent.count(elem) != 0)
        return;
      parent[elem] = elem;
      rank[elem] = 1;
      count++;
    }
    void toUnion(T x1, T x2) {
      T f1 = find(x1);
      T f2 = find(x2);
      if (rank[f1] > rank[f2]) {
        parent[f2] = f1;
        rank[f1] += rank[f2];
      } else {
        parent[f1] = f2;
        rank[f2] += rank[f1];
      }
      count--;
    }
    bool connected(T x1, T x2) {
      return find(x1) == find(x2);
    }
    int getCount() {
      return count;
    }
    std::unordered_map<T, T> getNodeMap() {
      return parent;
    }
    int getMaxRank() {
      int maxSize = 0;
      for (auto &[key, value] : parent) {
        if (key == value) {
          maxSize = std::max(maxSize, rank[key]);
        }
      }
      return maxSize;
    }
};
int longestConsecutive(vector<int>& nums) {
  std::unordered_set<int> numSet;
  Disjoint<int> joint;
  for (const auto &num : nums) {
    numSet.emplace(num); 
  }
  for (auto num : numSet) {
    joint.addElem(num);
  }
  for (auto num : numSet) {
    if (numSet.count(num + 1)) {
      joint.toUnion(num, num + 1);
    }
  }
  return joint.getMaxRank();
}

int main()
{
   vector<int> nums{100,4,200,1,3,2};
   //vector<int> nums{0,3,7,2,5,8,4,6,0,1};
   //vector<int> nums{};
   auto num = longestConsecutive(nums);
   std::cout << "ret: " << num << std::endl;
   return 0;
}