/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
  //  贪心不了一点，还得遍历完所有的状态

  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size(), m = s2.size();
    if (n + m != s3.size()) {
      return false;
    }

    // vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
    bool dp[110][110];
    memset(dp, 0, sizeof dp);
    dp[0][0] = true;
    s1 = ' ' + s1, s2 = ' ' + s2;
    s3 = ' ' + s3;

    for (int i = 1; i <= n; ++i) {
      if (s1[i] == s3[i]) {
        dp[i][0] = true;
      } else {
        break;
      }
    }

    for (int i = 1; i <= m; ++i) {
      if (s2[i] == s3[i]) {
        dp[0][i] = true;
      } else {
        break;
      }
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s1[i] == s3[i + j]) {
          dp[i][j] |= dp[i - 1][j];
        }
        if (s2[j] == s3[i + j]) {
          dp[i][j] |= dp[i][j - 1];
        }
      }
    }

    return dp[n][m];
  }
};
// @lc code=end
