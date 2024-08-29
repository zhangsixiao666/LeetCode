/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(!n){
            return 0;
        }
        int i = 0, j = n - 1;
        while(i<j) {
            if(nums[i]==val) {
                swap(nums[i], nums[j]);
                --j;
            }else {
                ++i;
            }
        }

        return i + (nums[i]!=val);
    }
};
// @lc code=end

