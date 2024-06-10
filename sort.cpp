#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"
using namespace std;

// 选择排序，循环数组，每轮从未排序的数组里最值和未排序数组里的第一个数交换（即已排序区间的末尾）
// 时间复杂度：O(n2)  空间复杂度：O(1)，原地排序
// 非稳定排序，输出可能会打乱数值一样的输入
// 非自适应排序，即时间复杂度不受输入数据影响
std::vector<int> selectionSort(vector<int> nums) {
  int len = nums.size();
  // i表示未排序数组里的第一个数或者已排序区间的后一个数
  // 如果遍历到区间仅剩一个数，不需要再排序，因此i取到len-2就可以了
  for (int i = 0; i < len - 1; i++) {
    // k表示未排序区间最值的索引
    int k = i; 
    // 遍历未排序区间，更新最值索引
    for (int j = i + 1; j < len; j++) {
      if (nums[j] < nums[k]) {
        k = j;
      }
    }
    // 交换未排序区间第一个数和最值索引
    std::swap(nums[i], nums[k]);
  }
  return nums;
}

// 冒泡排序，每轮将一个数冒泡到终点
// 从数组最左端开始向右遍历，依次比较相邻元素大小，如果“左元素 > 右元素”就交换二者。遍历完成后，最大的元素会被移动到数组的最右端。
std::vector<int> bubbleSort(vector<int> nums) {
  int len = nums.size();
  // 第一层循环确定每轮冒泡的区间终点，如果只剩一个元素，不需要再遍历，所以i > 0，不遍历i=0
  for (int i = len - 1; i > 0; i--) {
    // 因为是相邻两个数比较，因此，j遍历区间终点不包括i
    for (int j = 0; j < i; j++) {
      if (nums[j] > nums[j+1]) {
        std::swap(nums[j], nums[j + 1]);
      }
    }
  }
  return nums;
}

// 冒泡排序效率优化
// 使用flag，如果在这一轮的冒泡中没有数据交换，即已经完成排序，直接退出
// 时间复杂度：O(n2)，输入完全有序的情况下为O(n)   空间复杂度：O(1),原地排序
// 自适应排序，因为时间复杂度和输入数据的顺序有关
// 稳定排序，冒泡排序遇到相等元素不交换
std::vector<int> bubbleSortWithFlag(vector<int> nums) {
  int len = nums.size();
  for (int i = len - 1; i > 0; i--) {
    bool flag = false;
    for (int j = 0; j < i; j++) {
      if (nums[j] > nums[j+1]) {
        std::swap(nums[j], nums[j + 1]);
        flag = true;
      }
    }
    if (!flag) {
      break;
    }
  }
  return nums;
}

// 插入排序：我们在未排序区间选择一个基准元素，将该元素与其左侧已排序区间的元素逐一比较大小，并将该元素插入到正确的位置。
std::vector<int> insertionSort(std::vector<int> nums) {
  int len = nums.size();
  // 认为 i = 0的元素已排序，因此从i=1开始，[i~]
  for (int i = 1; i < len; i++) {
    // base
    int base = nums[i], j = i - 1;

  }
  return nums;
}

int main()
{
   std::vector<int> nums{2,1,8,7,4,1,3};
   auto res = selectionSort(nums);
   std::cout << "selection sort: " << std::endl;
   print(res);
   res = bubbleSort(nums);
   std::cout << "bubble sort: " << std::endl;
   print(res);
   res = bubbleSortWithFlag(nums);
   std::cout << "bubble sort with flag: " << std::endl;
   print(res);
   res = insertionSort(nums);
   std::cout << "insertion sort: " << std::endl;
   print(res);
   return 0;
}