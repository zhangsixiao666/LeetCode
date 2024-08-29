#include<bits/stdc++.h>
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<int, string> mp {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };
        
        for(auto c : digits) {
            int x = c - '0';
            if(res.empty()) {
                auto sz = mp[x].size();
                res = vector<string>(sz, "");
                for(int i = 0; i < sz; ++i) {
                    res[i]+=mp[x][i];
                }
            } else {
                auto sz = mp[x].size();
                vector<string> t;
                for(int i = 0; i < sz; ++i) {
                    vector<string> tmp = res;
                    for(int j = 0; j < res.size(); ++j) {
                        tmp[j]+=mp[x][i];
                    }
                    t.insert(t.end(), tmp.begin(), tmp.end());
                }
                res = t;
            }
        }

        return res;
    }
};
// @lc code=end

