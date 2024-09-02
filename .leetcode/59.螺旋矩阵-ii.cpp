/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        using PII = pair<int, int>;

        vector<PII> dist{{0,1},{1,0},{0,-1}, {-1, 0}};
        int x = 0, y = -1;
        int idx = 0;
        for(int i = 1; i <= n*n; ++i) {
            x+=dist[idx].first, y+=dist[idx].second;
            // cout << x << ' ' << y << endl;
            res[x][y] = i;
            int a = x + dist[idx].first, b = y + dist[idx].second;
            if(a<0 or a>=n or b<0 or b>=n or res[a][b]) {
                idx = (idx + 1)%4;
            }
        }

        return res;
    }
};
// @lc code=end

