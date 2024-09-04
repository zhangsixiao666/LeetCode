/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution {
public:
  int maxConsecutiveAnswers(string &s, int k) {
    // 滑动窗口的while中检查不满足的条件很清晰
    int n = s.size();

    int cnt = 0;
    int res = 0;

    for (int i = 0, j = 0; j < n; ++j) {
        cnt+=s[j]=='F';
        while(cnt>k) {
            if(s[i]=='F') {
                --cnt;
            }
            ++i;
        }
        res = max(res, j - i+1);
    }

    cnt = 0;
    for (int i = 0, j = 0; j < n;++j) {
        cnt+=s[j]=='T';
        while(cnt>k) {
            if(s[i]=='T') {
                --cnt;
            }
            ++i;
        }
        res = max(res, j - i+1);
    }

    return res;
  }
};
// @lc code=end
