/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        constexpr int N = 15;
        bool col[N][N], row[N][N], matrix[3][3][N];

        memset(col, 0, sizeof col);
        memset(row, 0, sizeof row);
        memset(matrix, 0, sizeof matrix);


        for(int i = 0; i <9;++i) {
            for(int j = 0; j < 9;++j) {
                auto c = board[i][j];
                if(c!='.') {
                    auto x = c - '0';
                    col[j][x] = true;
                    row[i][x] = true;
                    matrix[i/3][j/3][x] = true;
                }
            }
        }

        auto dfs = [&](auto&& dfs, int x, int y) -> bool {
            if(x==9) {
                return true;
            }
            if(y==9) {
                return dfs(dfs, x + 1, 0);
            }
            // process [x, y] position
            auto c = board[x][y];
            if(c!='.') {
                return dfs(dfs, x , y+1);
            }
            
            for(int i = 1; i <=9;++i) {
                if(!row[x][i] and !col[y][i] and !matrix[x/3][y/3][i]) {
                    board[x][y] = i + '0';
                    row[x][i] = col[y][i] = matrix[x/3][y/3][i] = true;
                    
                    if(dfs(dfs, x, y+1)) {
                        return true;
                    }
                    board[x][y] = '.';
                    row[x][i] = col[y][i] = matrix[x/3][y/3][i] = false;
                }
            }
            
            return false;
        };

        dfs(dfs, 0, 0);
        // cout << dfs(dfs, 0, 0) << endl;        
    }
};
// @lc code=end

