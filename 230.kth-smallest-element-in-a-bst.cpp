/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */
#include <stack>

using std::stack;

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
public:
    // The result of in-order traversal of a BST is sorted.

    /*
    // Recursive version
    // T: O(k)
    // S: O(k)
    int kthSmallest(TreeNode* root, int& k) {
        if (!root) return -1; // root->val >= 0
        int x = kthSmallest(root->left, k);
        if (!k) return x; // k already becomes 0 while visiting left subtree
        if (!--k) return root->val; // k becomes 0 at current node
        return kthSmallest(root->right, k); // continue visit right subtree
    }
    */

    // Iterative version
    // T: O(k)
    // S: O(k)
    int kthSmallest(TreeNode* root, int& k) {
        stack<TreeNode*> stk;
        while (true) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top(); stk.pop();
            if (!--k) return root->val;
            root = root->right;
        }
    }
};
// @lc code=end

