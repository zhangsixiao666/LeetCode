/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    // 注意数量关系推出合法性
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;

        auto dfs = [&](auto&& dfs, int left, int right) -> void {
            if(right==0) {
                res.emplace_back(path);
            }
            if(left>0) {
                path+='(';
                dfs(dfs, left - 1, right);
                path.pop_back();
            }
            if(right>left) {
                path+=')';
                dfs(dfs, left, right - 1);
                path.pop_back();
            }
        };

        dfs(dfs, n, n);

        return res;
    }
};
// @lc code=end

