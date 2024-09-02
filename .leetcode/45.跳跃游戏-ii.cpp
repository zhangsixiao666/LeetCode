/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
  // 不是On 不是On?
  int jump(vector<int> &nums) {
    int times = 0;
    int idx = 0;
    int pre = 0;
    int n = nums.size();

    while (idx < n - 1) {
      ++times;
      auto mx = idx;
      for (int i = pre; i < n and i <= idx; ++i) {
        mx = max(mx, nums[i] + i);
      }
      pre = idx + 1;
      idx = mx;
    }

    return times;
  }
};
// @lc code=end
