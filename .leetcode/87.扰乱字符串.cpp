/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
  bool isScramble(string s1, string s2) {
    int n = s1.size();
    if (n != s2.size()) {
      return false;
    }

    bool dp[35][35][35];
    memset(dp, 0, sizeof dp);

    s1 = ' ' + s1;
    s2 = ' ' + s2;

    // 枚举每个起始点 i, j
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j][1] = s1[i] == s2[j];
        for (int len = 2; i + len - 1 <= n && j + len - 1 <= n; ++len) {
          for (int k = 1; k < len; ++k) {
            bool case1 = dp[i][j][k] && dp[i + k][j + k][len - k];
            bool case2 = dp[i][j + len - k][k] && dp[i + k][j][len - k];
            dp[i][j][len] |= (case1 || case2);
          }
        }
      }
    }

    return dp[1][1][n];
  }
};

// @lc code=end
