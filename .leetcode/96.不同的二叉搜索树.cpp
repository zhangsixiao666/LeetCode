/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {

        vector<vector<int>> memo(n+10, vector<int>(n+10, 0));
        auto dfs = [&](auto&& dfs, int l, int r) {
            auto &mem = memo[l][r];
            if(mem) {
                return mem;
            }
            if(l>=r) {
                return mem=1;
            }

            auto res = 0;

            for(int i = l; i <= r; ++i) {
                auto left = dfs(dfs, l,  i -1);
                auto right = dfs(dfs, i + 1, r);

                res+=left*right;
            }

            return mem=res;
        };

        return dfs(dfs, 1, n);
    }
};
// @lc code=end

