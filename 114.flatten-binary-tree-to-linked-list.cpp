/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
public:
    // T: O(N)
    // S: O(1) (C/C++ tail recursion)
    void flatten(TreeNode* root) {
        if (!root)  return;

        flatten(root->left);
        flatten(root->right);

        // Connects the left subtree to the right of current node
        TreeNode *left = root->left, *right = root->right;
        root->left = nullptr;
        root->right = left;

        // Finds the end of left subtree which is just connected to the right 
        // and then attach the right subtree
        TreeNode *ptr = root;
        while (ptr->right)  ptr = ptr->right;
        ptr->right = right;
    }
};
// @lc code=end

