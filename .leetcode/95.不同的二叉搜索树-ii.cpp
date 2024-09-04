/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        auto dfs = [&](auto&& dfs, int l, int r) -> vector<TreeNode*>{
            if(l>r) {
                return vector<TreeNode*>{nullptr};
            }else if(l==r) {
                return vector<TreeNode*>{new TreeNode(l)};
            }

            vector<TreeNode*> res;

            for(int i = l ; i<=r; ++i) {
                
                auto left = dfs(dfs, l, i-1);
                auto right = dfs(dfs, i + 1, r);

                for(const auto& le: left) {
                    for(const auto& ri: right) {
                        auto root = new TreeNode(i);
                        root->left = le;
                        root->right = ri;
                        res.emplace_back(root);
                    }
                }

            }

            return res;
        };

        return dfs(dfs, 1, n);
    }
};
// @lc code=end

