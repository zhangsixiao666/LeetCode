/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
    vector<vector<string>> res;
    vector<string> path(n, string(n, '.'));
    vector<bool> diag1(2 * n + 5, false), diag2(2 * n + 5, false);
    vector<bool> row(n, false), col(n, false);

    auto dfs = [&](auto &&dfs, int x, int y, int u) {
      if (u == 0) {
        
        return 1;
      }
      if (x == n) {
        return 0;
      }
      if (y == n) {
        return dfs(dfs, x + 1, 0, u);
      }
      if (row[x]) {
        return dfs(dfs, x + 1, 0, u);
      }
      if (col[y]) {
        return dfs(dfs, x, y + 1, u);
      }
      if (diag1[x + y] or diag2[y - x + n]) {
        return dfs(dfs, x, y + 1, u);
      }
      int sum = dfs(dfs, x, y + 1, u);

      path[x][y] = 'Q';
      diag1[x + y] = diag2[y - x + n] = row[x] = col[y] = true;
      sum += dfs(dfs, x + 1, 0, u - 1);
      diag1[x + y] = diag2[y - x + n] = row[x] = col[y] = false;
      path[x][y] = '.';

      return sum;
    };

    return dfs(dfs, 0, 0, n);

    }
};
// @lc code=end

