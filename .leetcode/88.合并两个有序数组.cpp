/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int len = nums1.size();
    int p = m - 1;
    int q = n - 1;
    for (int i = len - 1; i >= 0; --i) {
      auto t = 0;
      if (p >= 0 and q >= 0) {
        if (nums1[p] >= nums2[q]) {
          t = nums1[p--];
        } else {
          t = nums2[q--];
        }
      } else if (p >= 0) {
        t = nums1[p--];
      } else {
        t = nums2[q--];
      }
      nums1[i] = t;
    }

  }
};
// @lc code=end
