/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;

        int a = intervals[0][0], b = intervals[0][1];

        for(int i = 1; i < n; ++i) {
            auto l = intervals[i][0], r = intervals[i][1];

            if(b< l) {
                res.emplace_back(vector<int>{a,b});
                 a = l, b = r;
            } else {
                b = max(b, r);
            }
        }

        res.emplace_back(vector<int>{a, b});

        return res;
    }
};
// @lc code=end

