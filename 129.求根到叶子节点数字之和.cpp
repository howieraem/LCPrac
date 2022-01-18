/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }

private:
    int helper(TreeNode* root, int res) {
        if (root == nullptr)  return 0;
        int tmp = res*10 + root->val;
        if (root->left == nullptr && root->right == nullptr)  return tmp;
        return helper(root->left, tmp) + helper(root->right, tmp);
    }
};
// @lc code=end
