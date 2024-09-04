/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == '1') {
          dp[i + 1][j] += dp[i][j] + 1;
        }
      }
    }

    // [1...n]

    auto maxArea = [](vector<int> &h) {
      int n = h.size();
      vector<int> l(n, -1), r(n, n);

      stack<int> stk;

      for (int i = 0; i < n; ++i) {
        auto x = h[i];
        while (!stk.empty() and x <= h[stk.top()]) {
          stk.pop();
        }
        if (!stk.empty()) {
          l[i] = stk.top();
        }
        stk.push(i);
      }
      // !!! why no clear
      stk = stack<int>();

      for (int i = n - 1; i >= 0; --i) {
        auto x = h[i];
        while (!stk.empty() and x <= h[stk.top()]) {
          stk.pop();
        }
        if (!stk.empty()) {
          r[i] = stk.top();
        }
        stk.push(i);
      }

      int res = 0;
      for (int i = 0; i < n; ++i) {
        res = max(res, h[i] * (r[i] - l[i] - 1));
      }
      return res;
    };

    int res = 0;
    for (int i = 1; i <= n; ++i) {
      auto t = maxArea(dp[i]);
      res = max(res, t);
    }
    return res;
  }
};
// @lc code=end
