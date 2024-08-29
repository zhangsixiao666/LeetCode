/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
  bool isMatch(string s, string p) {
    // 还可以压缩一下 减少比较次数 连续的*和单个*是一个效果
    int n = s.size(), m = p.size();
    if (m and p == string(m, '*')) {
      return true;
    }
    if (!(m + n)) {
      return true;
    }
    if (!m or !n) {
      return false;
    }
    constexpr int N = 2010;
    bool dp[N][N];

    memset(dp, 0, sizeof dp);
    dp[0][0] = true;

    s = ' ' + s, p = ' ' + p;
    int k = 1;
    while (k <= m and p[k] == '*') {
        cout << " k = " << k << endl;
      for (int i = 0; i <= n; ++i) {
        dp[i][k] = true;
      }
      ++k;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (p[j] == '?' or s[i] == p[j]) {
          dp[i][j] |= dp[i - 1][j - 1];
        } else if (p[j] == '*') {
          dp[i][j] |= dp[i][j - 1];
          dp[i][j] |= dp[i - 1][j];
        }
      }
    }
    // for (int i = 0; i <= n; ++i) {
    //   for (int j = 0; j <= m; ++j) {
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    return dp[n][m];
  }
};
// @lc code=end
