/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int a = newInterval[0], b = newInterval[1];

        int l = -1;
        int r = n;
        for(int i = 0; i < n; ++i) {
            auto inter = intervals[i];
            if(l==-1 and inter[1]>=a) {
                l = i;
            }
            if(r==n and inter[0]<=b) {
                r = i;
            }
        }
        cout << " l = " << l << " r = " << r << endl;
        if(l!=-1) {
            a = min(a, intervals[l][0]);
        }
        if(r!=n) {
            b = max(b, intervals[r][1]);
        }
        for(int i = 0; i < n; ++i) {
            if(i<l or i >r) {
                res.emplace_back(intervals[i]);
            } else if(i==l) {
                res.emplace_back(vector<int>{a,b});
                i = r;
            } 
        }

        return res;
    }
};
// @lc code=end

