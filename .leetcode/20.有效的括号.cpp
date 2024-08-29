/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
  // 看到括号匹配，操作符之类的 天然栈
  bool isValid(string s) {
    stack<char> stk;
    set<char> st{'(', '[', '{'};
    for (auto c : s) {
      if (st.find(c) != st.end()) {
        stk.push(c);
      } else {
        if (stk.empty()) {
          return false;
        }
        auto top = stk.top();
        // elegant
        if (c - top <= 2 and c - top >= 1) {
          stk.pop();
        } else {
          return false;
        }
      }
    }
    return stk.empty();
  }
};
// @lc code=end
