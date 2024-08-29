/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
  // 找到一种方式去划分掉这些水同时方便计算 wochao 居然没用单调栈
  int trap(vector<int> &height) {
    int n = height.size();
    int maxLen = 0;
    int idx = -1;
    vector<int> l(n, 0), r(n, n);
    for (int i = 0; i < n; ++i) {
      l[i] = idx;
      auto x = height[i];
      if (x >= maxLen) {
        maxLen = x;
        idx = i;
      }
    }
    maxLen = 0;
    idx = n;
    for (int i = n - 1; i >= 0; --i) {
      r[i] = idx;
      auto x = height[i];
      if (x >= maxLen) {
        maxLen = x;
        idx = i;
      }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (l[i] != -1 and r[i] != n) {
        int left = height[l[i]], right = height[r[i]];
        auto x = height[i];
        auto mn = min(left, right);
        if (mn > x) {
          res += (mn - x);
        }
      }
    }

    return res;
  }
};
// @lc code=end
