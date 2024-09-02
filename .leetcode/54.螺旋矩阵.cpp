/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        using PII = pair<int, int>;

        vector<vector<bool>> is_used(n, vector<bool>(m, false));

        vector<PII> dist {
            {0,1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<int> res;

        int x = 0, y = -1;
        int idx = 0;
        while(res.size()<n*m) {
            x+=dist[idx].first, y+=dist[idx].second;
            is_used[x][y] = true;
            res.emplace_back(matrix[x][y]);

            int a = x + dist[idx].first, b = y + dist[idx].second;
            if(a<0 or a>=n or b<0 or b>=m or is_used[a][b]) {
                idx = (idx + 1)%4;
            }
        }

        return res;
    }
};
// @lc code=end

