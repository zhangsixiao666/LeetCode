/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> path(n, -1);
        vector<vector<int>> res;
        vector<bool> is_used(n, false);

        auto dfs =[&](auto&& dfs, int idx) -> void {
            if(idx == n) {
                res.emplace_back(path);
                return ;
            }

            for(int i = 0; i < n; ++i) {
                if(!is_used[i]) {
                    is_used[i] = true;
                    path[idx] = nums[i];
                    dfs(dfs, idx+1);
                    is_used[i] = false;
                }
            }
        };

        dfs(dfs, 0);

        return res;
    }
};
// @lc code=end

