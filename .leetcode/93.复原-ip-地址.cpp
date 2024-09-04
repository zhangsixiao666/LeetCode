/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    int n = s.size();

    vector<vector<int>> idxs;
    vector<int> path;
    auto dfs = [&](auto &&dfs, int idx) {
      if (path.size() == 3) {
        idxs.emplace_back(path);
        return;
      }
      if (idx >= n) {
        return;
      }

      for (int i = idx; i <= n - 1; ++i) {
        path.push_back(i);
        dfs(dfs, i + 1);
        path.pop_back();
      }
    };

    dfs(dfs, 1);

    auto check = [&](vector<int> &p) -> string {
      int a = p[0], b = p[1], c = p[2];
      auto ss1 = s.substr(0, a);
      auto ss2 = s.substr(a, b - a);
      auto ss3 = s.substr(b, c - b);
      auto ss4 = s.substr(c);

      auto check_ss = [](string &ss) -> bool {
        if (ss.size() > 3 or ss.size() > 1 and ss[0] == '0') {
          return false;
        }
        auto num = stoi(ss);
        if (num > 255) {
          return false;
        }
        return true;
      };

      if (check_ss(ss1) and check_ss(ss2) and check_ss(ss3) and check_ss(ss4)) {
        return ss1 + '.' + ss2 + '.' + ss3 + '.' + ss4;
      }

      return string();

    };

    vector<string> res;
    for (auto &idx : idxs) {
      string t = check(idx);
      if (t.size()) {
        res.emplace_back(std::move(t));
      }
    }

    return res;
  }
};
// @lc code=end
