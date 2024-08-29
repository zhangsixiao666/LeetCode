/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n - 2;
        while(j>=0 and nums[j]>=nums[j+1]) {
            --j;
        }

        if(j>=0) {
            int k = n - 1;
            while(k>=0 and nums[k]<=nums[j]) {
                --k;
            }
            swap(nums[k], nums[j]);
        }
        sort(nums.begin() + j + 1, nums.end(), less<int>());



    }
};
// @lc code=end

