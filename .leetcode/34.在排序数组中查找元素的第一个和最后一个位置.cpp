/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // 两次二分秒了
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) {
            return {-1,-1};
        }
        int l = 0, r = n - 1;
        while(l<r) {
            int mid = (l+r)>>1;
            if(nums[mid]>=target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(nums[l]!=target) {
            return {-1, -1};
        }
        int t = l;
        l = 0, r = n - 1;
        while(l<r) {
            int mid = (l+r+1)>>1;
            if(nums[mid]<=target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return {t, l};
    }
};
// @lc code=end

