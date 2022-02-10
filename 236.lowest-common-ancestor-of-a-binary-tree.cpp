/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    // If the current (sub)tree contains both p and q, then the function result is their LCA. 
    // If only one of them is in that subtree, then the result is that one (IMPORTANT CONDITION).
    // If neither are in that subtree, then the result is null.
    // T: O(n), n := the number of nodes
    // S: O(n) (recursion stack)
    TreeNode* lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) {
        if (!root || root == p || root == q)  return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q),
                 *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)  return root;
        return left ? left : right; // if left is not null return left, else return right
    }
};
// @lc code=end

