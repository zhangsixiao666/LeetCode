/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
  vector<int> grayCode(int n) {
    // 2^n
    vector<int> pre{0, 1};
    if (n == 1) {
      return pre;
    }
    vector<int> res;
    bool reverse = true;
    for (int i = 2; i <= n; ++i) {
      res = vector<int>();

      for (auto x : pre) {
        if (reverse) {
          res.emplace_back(x << 1);
          res.emplace_back((x << 1) + 1);
        } else {
          res.emplace_back((x << 1) + 1);
          res.emplace_back(x << 1);
        }
        reverse = !reverse;
      }
      pre = res;
    }

    return res;
  }
};
// @lc code=end
