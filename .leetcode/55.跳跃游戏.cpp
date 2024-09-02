/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int mx = 0;
    int pre = 0;
    int n = nums.size();
    while (mx < n - 1) {
    //   cout << "mx: " << mx << endl;
      int t = mx;
      for (int i = pre; i <= mx; ++i) {
        t = max(t, nums[i] + i);
      }
      pre = mx + 1;
      mx = t;
      // 无法步进
      if(pre>mx) {
        break;
      }
    }
    // cout << "mx: " << mx << endl;
    return mx >= n - 1;
  }
};
// @lc code=end
