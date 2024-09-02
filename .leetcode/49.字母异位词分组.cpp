/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(const auto& ss : strs) {
            auto tmp = ss;
            sort(tmp.begin(), tmp.end());
            mp[tmp].emplace_back(ss);
        }
        vector<vector<string>> res;

        for(const auto[_, v] : mp) {
            res.emplace_back(v);
        }

        return res;
    }
};
// @lc code=end

