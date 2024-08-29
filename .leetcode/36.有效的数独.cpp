/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
  // board 9*9
  bool isValidSudoku(vector<vector<char>> &board) {
    bool is_used[10];

    for (int i = 0; i < 9; ++i) {
      memset(is_used, 0, sizeof is_used);
      for (int j = 0; j < 9; ++j) {
        auto c = board[i][j];
        if (c != '.') {
          auto x = c - '1';
          if (is_used[x]) {
            return false;
          }
          is_used[x] = true;
        }
      }
    }

    for (int i = 0; i < 9; ++i) {
      memset(is_used, 0, sizeof is_used);
      for (int j = 0; j < 9; ++j) {
        auto c = board[j][i];
        if (c != '.') {
          auto x = c - '1';
          if (is_used[x]) {
            return false;
          }
          is_used[x] = true;
        }
      }
    }

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        memset(is_used, 0, sizeof is_used);
        for (int p = 0; p < 3; ++p) {
          for (int q = 0; q < 3; ++q) {
            auto c = board[i * 3 + p][j * 3 + q];
            if (c != '.') {
              auto x = c - '1';
              if (is_used[x]) {
                return false;
              }
              is_used[x] = true;
            }
          }
        }
      }
    }

    return true;
  }
};
// @lc code=end
