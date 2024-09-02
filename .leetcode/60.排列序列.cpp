/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    
    string getPermutation(int n, int k) {
        vector<int> fac(15, 0);

        fac[1] = 1;
        for(int i = 2;i<=9;++i) {
            fac[i] = fac[i-1] * i;
        }

        vector<int> sub(n,0);

        for(int i = 1; i <=9; ++i) {
            sub[i] = i;
        }

        string res = "";

        int len = n - 1;
        while(k) {
            int sz = fac[len];
            int number = k/sz;
            k%=sz;
            number++;
            cout << number << endl;
            sort(sub.begin(), sub.end());

            res+=to_string(sub[number]);
            
            for(auto iter=sub.begin(); iter!=sub.end(); ++iter) {
                if(*iter==sub[number]) {
                    sub.erase(iter);
                    break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

