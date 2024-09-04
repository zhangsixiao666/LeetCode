/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;

        sort(nums.begin(), nums.end());
        
        auto dfs = [&](auto&& dfs, int idx) -> void {
            if(idx==n+1) {
                return;
            }
            res.emplace_back(path);

            for(int i = idx; i<n; ++i) {
                if(i!=idx and nums[i]==nums[i-1])
                    continue;
                path.emplace_back(nums[i]);
                dfs(dfs, i+1);
                path.pop_back();
            }

        };

        dfs(dfs, 0);

        return res;
    }
};
// @lc code=end

