/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    // 二分妙
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l<r) {
            int mid = (l+r+1)>>1;
            if(nums[mid]>=nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << " l = " << l << " nums[l]: " << nums[l] << endl;
        // now l=r is the 
        if(target>=nums[0]) {
            l = 0;
            while(l<r) {
                int mid = (l+r)>>1;
                if(nums[mid]>=target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } 

        } else {
            l = l + 1, r = n - 1;
            if(l>=r) {
              return nums[r]==target?l:-1;  
            }
            while(l<r) {
                int mid = (l+r)>>1;
                if(nums[mid]>=target) {
                    r = mid;
                }else {
                    l = mid + 1;
                }
            }
        }
        return nums[l]==target?l:-1;
    }
};
// @lc code=end

