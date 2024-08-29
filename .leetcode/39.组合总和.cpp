/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    // 唯一一点，怎么去重
    // 1. 先sort, 重复的数字就排在一起了
    // 2. 重复的本质就是相同的位置放上了不同的数值相同的数
    // 3. 有两种重复的定义，看顺序是否作为重复的依据 若是作为，则保证每次都在后面调，若不作为，就随便挑，也就是[2,3], [3,2]
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> res;
        vector<int> path;

        sort(c.begin(), c.end());

        int n = c.size();
        auto dfs = [&](auto&& dfs, int idx, int sum) -> void {
            if(sum==target) {
                res.emplace_back(path);
                return ;
            }
            if(sum>target or idx>=n) {
                return ;
            }
            for(int i = idx; i< n; ++i){
                if(i and c[i]==c[i-1])
                    continue;
                auto x = c[i];
                path.push_back(x);
                dfs(dfs, i, x + sum);
                path.pop_back();
            }
            
        };

        dfs(dfs, 0, 0);

        return res;
    }
};
// @lc code=end

