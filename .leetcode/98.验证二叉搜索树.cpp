/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long pre = LLONG_MIN;

        auto dfs = [&](auto&& dfs, TreeNode* root) -> bool{
            if(root) {
                if(!dfs(dfs, root->left))
                    return false;
                if(pre>=root->val) {
                    return false;
                } else {
                    pre = root->val;
                }

                if(!dfs(dfs, root->right))
                    return false;
            }

            return true;

        };

        return dfs(dfs, root);
    }
};
// @lc code=end

