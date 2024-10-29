/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    bool traverse(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) {
            return true;  // the parent node is a leaf node
        }
        if (l != nullptr || r != nullptr || l->val != r->val) {
            return false;
        }
        return traverse(l->left, r->right) && traverse(l->right, r->left);
    }

public:
    // T: O(n)
    // S: O(1) tail recursion
    bool isSymmetric(TreeNode* root) {
        return root == nullptr ? true : traverse(root->left, root->right);
    }
};
// @lc code=end

