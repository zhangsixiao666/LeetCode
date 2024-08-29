/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        int n = c.size();
        vector<int> path;
        vector<vector<int>> res;

        sort(c.begin(), c.end());

        auto dfs = [&](auto&& dfs, int cur, int sum) -> void{
            if(sum==target) {
                res.emplace_back(path);
                return;
            }
            if(sum > target or cur >= n) {
                return;
            }

            for(int i = cur; i < n; ++i) {
                if(i!=cur and c[i]==c[i-1])
                    continue;
                path.push_back(c[i]);
                dfs(dfs, i+1, sum+c[i]);
                path.pop_back();
            }

        };

        dfs(dfs, 0, 0);

        return res;
    }
};
// @lc code=end

