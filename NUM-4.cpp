#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 方法一：归并排序
    // 方法二：二分查找
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int len1 = nums1.size();
      int len2 = nums2.size();
      if (len1 > len2) {
        return findMedianSortedArrays(nums2, nums1);
      }
      int k = (len1 + len2 + 1) / 2;
      int left = 0;
      int right = len1;
      while (left < right) {
        int m1 = left + (right - left) / 2;
        int m2 = k - m1;
        if (nums1[m1] < nums2[m2 - 1]) {
          left = m1 + 1;
        } else {
          right = m1;
        }
      }
      int m1 = left;
      int m2 = k - m1;
      int leftMax1 = INT_MIN, leftMax2 = INT_MIN;
      if (m1 > 0) {
        leftMax1 = nums1[m1 - 1];
      }
      if (m2 > 0) {
        leftMax2 = nums2[m2 - 1];
      }
      // 如果总数是奇数，取左半部分最大的值就是中位数
      int leftMax = std::max(leftMax1, leftMax2);
      if ((len1 + len2) % 2 == 1) {
        return (double)leftMax;
      }

      int rightMin1 = INT_MAX, rightMin2 = INT_MAX;
      if (m1 != len1) {
        rightMin1 = nums1[m1];
      }
      if (m2 != len2) {
        rightMin2 = nums2[m2];
      }
      // 如果总数是偶数，需要取左边最大和右边最小取平均
      int rightMin = std::min(rightMin1, rightMin2);
      return (leftMax + rightMin) / 2.0;
    }
};

int main()
{
   Solution s;
   std::vector<int> nums1{1, 3};
   std::vector<int> nums2{2};
   double res = s.findMedianSortedArrays(nums1, nums2);
   std::cout << "res: " << res << std::endl;
   return 0;
}