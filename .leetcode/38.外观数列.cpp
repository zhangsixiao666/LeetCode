/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) {
            return "1";
        }
        auto ss = countAndSay(n-1);

        string res = "";
        int m = ss.size();

        int i = 0, j = 0;
        while(j<m) {
            while(j<m and ss[j]==ss[i]) {
                ++j;
            }
            res += to_string(j-i) + ss[i];
            i =j ;
        }
        
        return res;
    }
};
// @lc code=end

