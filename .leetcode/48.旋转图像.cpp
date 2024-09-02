/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 1. 上下交换
        // 2. 主对角线交换

        int i = 0, j = n - 1;
        while(i<j) {
            for(int k = 0; k < n; ++k) {
                swap(matrix[i][k], matrix[j][k]);
            }
            ++i, --j;
        }
        int len = 0;
        for(int i = 1; i <n; ++i) {
            ++len;
            for(int j = 0; j<len; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end

