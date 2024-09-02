/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // 快速幂模板 毋需多言
    double myPow(double x, int n) {
        double res = 1;
        bool flag = n>=0;

        n = abs(n);
        while(n) {
            if(n&1) {
                res*=x;
            }
            x*=x;
            n>>=1;
        }
        if(!flag) {
            res = 1 / res;
        }
        return res;
    }
};
// @lc code=end

