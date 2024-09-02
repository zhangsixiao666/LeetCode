/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for(int i = 0; i < n; ++i) {
            dp[i] = nums[i];
        }
        int mx = nums[0];
        for(int i = 1; i < n; ++i) {
            dp[i]+=dp[i-1]>0?dp[i-1]:0;
            mx = max(mx, dp[i]);
        }

        return mx;
    }
};
// @lc code=end

