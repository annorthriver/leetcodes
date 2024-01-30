#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(const std::vector<int>& container)
{
    for (const int x : container)
        std::cout << x << ' ';
    std::cout << '\n';
}

// 方法一: 使用辅助数组以及vector的insert方法
void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return;
        }
        k = k % nums.size();
        int start = nums.size() - k;
        std::vector<int> newNum(nums.begin() + start, nums.end());
        newNum.insert(newNum.end(), nums.begin(), nums.begin() + start);
        nums.assign(newNum.begin(), newNum.end());
}
// 方法二：辅助数组，但是通过遍历原数组，索引变化规律是 i -> (i+k)%n

// 方法三：环状替换

// 方法四：数组翻转，需要三次


int main()
{
   std::vector<int> nums{1,2,3};
   rotate(nums,1);
   print(nums);
   return 0;
}