/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    // 两个点
    // 1. 小端(reverse) 2. 考虑进位(carry)
    string multiply(string n1, string n2) {
        int n = n1.size(), m = n2.size();

        vector<int> ss1(n), ss2(m);
        for(int i = 0; i < n; ++i) {
            ss1[i] = n1[n-1-i] - '0';
        }

        for(int i = 0; i < m; ++i) {
            ss2[i] = n2[m-1-i] - '0';
        }

        // n位乘m位的结果最长是 n+m+1?
        vector<int> res(n+m, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                res[i+j]+=ss1[i]*ss2[j];
            }
        }

        int carry = 0;
        string t = "";
        for(int i = 0; i <n+m;++i) {
            res[i]+=carry;
            carry=res[i]/10;
            res[i]%=10;
        }

        int i = n+m-1;
        while(i>=0 and res[i]==0) {
            --i;
        }
        if(i<0) {
            return "0";
        }
        while(i>=0) {
            t+=(res[i--]+'0');
        }

        return t;
    }
};
// @lc code=end

