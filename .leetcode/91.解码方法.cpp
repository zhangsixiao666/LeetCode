/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    s = ' ' + s;
    if (s[1] == '0') {
      return 0;
    }

    dp[0] = dp[1] = 1;
    // A~Z -> [1, 26]
    for (int i = 2; i <= n; ++i) {
      auto a = s[i-1] - '0';
      auto b = s[i] - '0';

      auto sum = 10 * a + b;
      if (sum >=10 and sum <= 26) {
        dp[i] += dp[i - 2];
      }
      if (b != 0) {
        dp[i] += dp[i - 1];
      }
    }
    // for(int i = 1; i <=n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    return dp[n];
  }
};
// @lc code=end
