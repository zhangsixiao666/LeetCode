/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> l(n, -1), r(n, n);
        stack<int> stk;

        for(int i = 0; i < n; ++i) {
            auto x = h[i];
            while(!stk.empty() and x<=h[stk.top()]) {
                stk.pop();
            }
            if(!stk.empty()) {
                l[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for(int i = n - 1; i>=0; --i) {
            auto x = h[i];
            while(!stk.empty() and x <= h[stk.top()]) {
                stk.pop();
            }
            if(!stk.empty()) {
                r[i] = stk.top();
            }
            stk.push(i);
        }

        int res = 0;

        for(int i = 0; i < n; ++i) {
            res = max(res, h[i]*(r[i]-l[i]-1));
        }

        return res;
    }
};
// @lc code=end

