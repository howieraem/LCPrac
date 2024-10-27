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
    // S: O(n) recursion stack worst case
    TreeNode* lowestCommonAncestor(TreeNode* root, const TreeNode* p, const TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            // Base case:
            // 1. Null root/child, indicating target not found on the current path
            // 2. If the current node is a target node, return the node directly 
            //    so that the outer recursions know that the descendant exists 
            //    in a relevant subtree
            return root;
        }

        // Post-order traversal
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Both p and q found under this node, and not in the same branch, 
        // the current node is therefore the LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // The LCA or at most one descendant found
        return left != nullptr ? left : right;
    }
};
// @lc code=end

