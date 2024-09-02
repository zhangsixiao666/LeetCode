/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        while(i>=0 and s[i]==' ') {
            --i;
        }
        int len = 0;
        while(i>=0 and s[i]!=' ') {
            --i, ++len;
        }

        return len;
    }
};
// @lc code=end

