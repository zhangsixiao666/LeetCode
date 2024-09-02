/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
  // n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> path(n, string(n, '.'));
    vector<bool> diag1(2 * n + 5, false), diag2(2 * n + 5, false);
    vector<bool> row(n, false), col(n, false);

    auto dfs = [&](auto &&dfs, int x, int y, int u) {
      if (u == 0) {
        res.emplace_back(path);
        return;
      }
      if (x == n) {
        return;
      }
      if (y == n) {
        dfs(dfs, x + 1, 0, u);
        return;
      }
      if (row[x]) {
        dfs(dfs, x + 1, 0, u);
        return;
      }
      if (col[y]) {
        dfs(dfs, x, y + 1, u);
        return;
      }
      if (diag1[x + y] or diag2[y - x + n]) {
        dfs(dfs, x, y + 1, u);
        return;
      }
      dfs(dfs, x, y + 1, u);

      path[x][y] = 'Q';
      diag1[x + y] = diag2[y - x + n] = row[x] = col[y] = true;
      dfs(dfs, x + 1, 0, u - 1);
      diag1[x + y] = diag2[y - x + n] = row[x] = col[y] = false;
      path[x][y] = '.';
    };

    dfs(dfs, 0, 0, n);

    return res;
  }
};
// @lc code=end
