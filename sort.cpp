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
    // 因为是相邻两个数比较，因此，j遍历区间终点不包括i，里面的j+1会遍历到
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
// 时间复杂度：O(n2)，如果数据有序，时间复杂度O(n)
// 空间复杂度：O(1)，原地排序
// 稳定排序：在插入操作过程中，我们会将元素插入到相等元素的右侧，不会改变它们的顺序。
// 自适应排序，因为时间复杂度和输入数据的顺序有关

// 插入排序的时间复杂度为 O(n2)，而我们即将学习的快速排序的时间复杂度为 O(nlogn)。尽管插入排序的时间复杂度更高，但在数据量较小的情况下，插入排序通常更快。
// 这个结论与线性查找和二分查找的适用情况的结论类似。快速排序这类O(nlogn)的算法属于基于分治策略的排序算法，往往包含更多单元计算操作。
// 而在数据量较小时，n2和nlogn的数值比较接近，复杂度不占主导地位，每轮中的单元操作数量起到决定性作用。

// 实际上，许多编程语言（例如 Java）的内置排序函数采用了插入排序，大致思路为：对于长数组，采用基于分治策略的排序算法，例如快速排序；对于短数组，直接使用插入排序。
// 虽然冒泡排序、选择排序和插入排序的时间复杂度都为 O(n2)，但在实际情况中，插入排序的使用频率显著高于冒泡排序和选择排序，主要有以下原因。
// 1. 冒泡排序基于元素交换实现，需要借助一个临时变量，共涉及 3 个单元操作；插入排序基于元素赋值实现，仅需 1 个单元操作。因此，冒泡排序的计算开销通常比插入排序更高。
// 2. 选择排序在任何情况下的时间复杂度都为 O(n2)。如果给定一组部分有序的数据，插入排序通常比选择排序效率更高。
// 3. 选择排序不稳定，无法应用于多级排序。
std::vector<int> insertionSort(std::vector<int> nums) {
  int len = nums.size();
  // 认为 i = 0的元素已排序，因此从i=1开始，[i~len)是未排序区间
  for (int i = 1; i < len; i++) {
    // base选定当前i对应的数，j是已排序区间的右边界
    int base = nums[i], j = i - 1;
    // 从j开始的数与base逐一比较(范围 0 ~ j)，如果比base大，都往右挪一个位置，否则将base插入到j+1的位置
    while(j >= 0 && nums[j] > base) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = base;
  }
  return nums;
}

// 快速排序：是一种基于分治策略的排序算法
// 快速排序的核心操作是“哨兵划分”，其目标是：选择数组中的某个元素作为“基准数”，将所有小于基准数的元素移到其左侧，而大于基准数的元素移到其右侧。
// 时间复杂度：O(nlogn)，平均情况下递归层数logn，每层循环n，最差情况下使用O(n2)时间
// 空间复杂度O(n)
// 自适应排序
// 原地排序，非稳定排序

// 快速排序相对于归并排序和堆排序的优势：
// 1. 出现最差情况的概率很低
// 2. 缓存使用效率高: 执行partition时，会将整个子数组加载到缓存，而堆需要跳跃式访问
// 3. 复杂度的常数系数少

// 划分的基准数优化
// 极端case:输入如果完全倒序，左子数组n-1,右子数组0，分治策略会失效，退化为冒泡排序的近似形式
// 优化：将数组的首，尾，中三点元素的中位数作为基准数
int midianThree(std::vector<int> &nums, int left, int mid, int right) {
  // 获取对应的数值
  int l = nums[left], m = nums[mid], r = nums[right];
  if ((l <= m && m <= r) || (r <= m && m <= l)) {
    return mid;
  }
  if ((m <= l && l <= r) || (r <= l && l <= m)) {
    return left;
  }
  return right;
}

int partition(std::vector<int> &nums, int left, int right) {
  int i = left, j = right;
  // 使用三中位数优化
  int mid = midianThree(nums, left, (left + right)/2, right);
  // 把中位数交换到最左侧
  std::swap(nums[mid], nums[left]);
  // 从nums的左右端点开始遍历，以nums[left]为基准元素，ij相遇时停止
  while (i < j) {
    // 找到从右向左第一个小于基准元素的数
    while (i < j && nums[j] >= nums[left]) {
      j--;
    }
    // 找到从左向右第一个大于基准元素的数
    while (i < j && nums[i] <= nums[left]) {
      i++;
    }
    // 交换这两个数
    std::swap(nums[i], nums[j]);
  }
  // 交换基准元素到数组分界线，使得左边的数都小于基准元素，右边的数都大于基准元素
  std::swap(nums[i], nums[left]);
  return i;
}

void quickSortOri(std::vector<int> &nums, int left, int right) {
  // 子数组长度为1，终止递归
  if (left >= right) {
    return;
  }
  // 哨兵划分
  int pivot = partition(nums, left, right);
  // 递归划分左子数组，右子数组
  quickSortOri(nums, left, pivot - 1);
  quickSortOri(nums, pivot + 1, right);
}

// 尾递归优化
// 极端case：如果数组完全有序，左子数组0，右子数组n-1,分治失效，需要O(n)的栈帧
// 可以确保递归深度不超过logn
// 注意：这里的尾递归并不是真正的尾递归，而是使用尾递归的方法优化栈深度
// https://www.cnblogs.com/babybluevino/p/3714022.html
void quickSortOpt1(std::vector<int> &nums, int left, int right) {
  while(left < right) {
    // 哨兵划分
    int pivot = partition(nums, left, right);
    quickSortOpt1(nums, left, pivot - 1);
    left = pivot + 1;
  }
}
// 为了防止栈帧空间的累积，我们可以在每轮哨兵排序完成后，比较两个子数组的长度，仅对较短的子数组进行递归
void quickSortOpt2(std::vector<int> &nums, int left, int right) {
  while(left < right) {
    // 哨兵划分
    int pivot = partition(nums, left, right);
    // 对两个子数组中较短的那个执行快速排序
    if (pivot - left < right - pivot) {
      quickSortOpt2(nums, left, pivot - 1);
      left = pivot + 1;
    } else {
      quickSortOpt2(nums, pivot + 1, right);
      right = pivot - 1;
    }
  }
}

// 归并排序：基于分治策略的排序算法，包括“划分”和“合并”阶段
// 划分阶段”从顶至底递归地将数组从中点切分为两个子数组直到数组长度为1.
// “合并阶段”从底至顶地将左子数组和右子数组合并为一个有序数组。这一阶段实际就是两个有序数组合并。

// 观察发现，归并排序与二叉树后序遍历的递归顺序是一致的。
// 后序遍历：先递归左子树，再递归右子树，最后处理根节点。
// 归并排序：先递归左子数组，再递归右子数组，最后处理合并。

// 合并左子数组和右子数组(两个有序数组)
void merge(vector<int> &nums, int left, int mid, int right) {
  // 左子数组区间为 [left, mid], 右子数组区间为 [mid+1, right]
  // 创建一个临时数组 tmp ，用于存放合并后的结果
  vector<int> tmp(right - left + 1);
  int i = left, j = mid + 1, k = 0;
  while (i <= mid && j <= right) {
    if (nums[i] <= nums[j]) {
      tmp[k++] = nums[i++];
    } else {
      tmp[k++] = nums[j++];
    }
  }
  while (i <= mid) {
    tmp[k++] = nums[i++];
  }
  while (j <= right) {
    tmp[k++] = nums[j++];
  }
  for (k = 0; k < tmp.size(); k++) {
    nums[left + k] = tmp[k];
  }
}

// 时间复杂度：O(nlogn)，空间复杂度O(n)
// 非自适应排序：即与输入数据顺序无关
// 非原地排序：O(logn)的栈帧空间，O(n)大小的额外空间
// 稳定排序：相等元素次序保持不变
// 可应用于链表排序
void mergeSort(vector<int> &nums, int left, int right) {
  // 数组长度为1，返回
  if (left >= right) {
    return;
  }
  // 划分
  int mid = left + (right - left) / 2;
  mergeSort(nums, left, mid);
  mergeSort(nums, mid + 1, right);
  // 合并
  merge(nums, left, mid, right);
}

// 堆排序：是一种基于堆数据结构实现的高效排序算法。
// 1. 输入数组并建立大顶堆。完成后，最大元素位于堆顶。
// 2. 将堆顶元素（第一个元素）与堆底元素（最后一个元素）交换。完成交换后，堆的长度减 1，已排序元素数量加 1。
// 3. 从堆顶元素开始，从顶到底执行堆化操作（sift down）。完成堆化后，堆的性质得到修复。
// 4. 循环执行第 2. 步和第 3. 步。循环 n-1 轮后，即可完成数组排序。
// 注意：这里求递增数组使用大顶堆，求递减数组使用小顶堆
void heapifyShiftDown(vector<int> &nums, int n, int i) {

  while (true) {
    /* 堆的长度为 n ，从节点 i 开始，从顶至底堆化 */
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    // 从顶至底执行堆化
    // 更新最大值对应的索引
    if (l < n && nums[l] > nums[max]) {
      max = l;
    }
    if (r < n && nums[r] > nums[max]) {
      max = r;
    }
    // 若节点 i 最大或索引 l, r 越界，则无须继续堆化，跳出
    if (max == i) {
      break;
    }
    std::swap(nums[i], nums[max]);
    i = max;
  }
}

// 时间复杂度：O(nlogn) 空间复杂度:O(1)
// 非自适应排序
// 原地排序
// 非稳定排序：在交换堆顶元素和堆底元素时，相等元素的相对位置可能发生变化。
void heapSort(vector<int> &nums) {
  int len = nums.size();
  // 建堆
  for (int i = len / 2 - 1; i >= 0; i--) {
    heapifyShiftDown(nums, len, i);
  }
  // 交换堆底和堆顶，当剩下一个元素时，不用再执行排序逻辑
  for (int i = len - 1; i > 0; i--) {
    std::swap(nums[i], nums[0]);
    // 以根节点为起点，从顶到底执行堆化
    heapifyShiftDown(nums, i, 0);
  }
}

// 桶排序
// 计数排序
// 基数排序

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
  res = nums;
  quickSortOpt2(res, 0, res.size() - 1);
  std::cout << "quick sort: " << std::endl;
  print(res);
  res = nums;
  mergeSort(res, 0, res.size() - 1);
  std::cout << "merge sort: " << std::endl;
  print(res);
  res = nums;
  heapSort(res);
  std::cout << "heap sort: " << std::endl;
  print(res);
  return 0;
}