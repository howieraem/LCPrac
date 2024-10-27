/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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
    // T: O(n)
    // S: O(n) recursion stack
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }

private:
    // Pre-order traversal
    int helper(TreeNode* root, int path_num) {
        if (root == nullptr) {
            return 0;
        }
        path_num *= 10;
        path_num += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            // Leaf node
            return path_num;
        }

        // Return sum of all root-to-leaf numbers
        return helper(root->left, path_num) + helper(root->right, path_num);
    }
};
// @lc code=end
