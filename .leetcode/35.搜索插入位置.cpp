/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l<r) {
            int mid = (l+r)>>1;
            if(nums[mid]>=target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

