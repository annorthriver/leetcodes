#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstdlib>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
      if (randomSet.count(val)) {
        return false;
      }
      randomSet.insert(val);
      return true;
    }
    
    bool remove(int val) {
      if (randomSet.count(val)) {
        randomSet.erase(val);
        return true;
      }
      return false;
    }
    
    int getRandom() {
      int randomVal = std::rand() % randomSet.size();
      auto iter = randomSet.begin();
      while (randomVal) {
        randomVal--;
        iter++;
      }
      return *iter;
    }
    std::unordered_set<int> randomSet;
};

int main()
{
   RandomizedSet* obj = new RandomizedSet();
   int val = 1;
   bool param_1 = obj->insert(val);
   val = 2;
   bool param_2 = obj->remove(val);
   val = 2;
   param_2 = obj->insert(val);
   int param_3 = obj->getRandom();
  return 0;
}