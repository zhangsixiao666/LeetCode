/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    // 难点 原地
    // 观察数据范围
    // 预处理负数+下标作为数出现与否的flag
    int firstMissingPositive(vector<int>& nums) {
        // 对于长度为n的数组，最小的没出现的正数是n+1
        int n = nums.size();

        for(int i =0; i < n; ++i) {
            if(nums[i]<=0)
            {
                nums[i] = n + 2;
            }
        }

        for(int i = 0; i < n; ++i) {
            // 有一个后效性
            auto x = abs(nums[i]);
            if(x>=1 and x<=n and nums[x-1]>=0) {
                nums[x-1]*=-1;
            }
        }

        for(int i = 0; i<n;++i) {
            auto x = nums[i];
            if(x>0) {
                return i+1;
            }
        }

        return n+1;
    }
};
// @lc code=end

