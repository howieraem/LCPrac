/*
 * @lc app=leetcode id=545 lang=cpp
 *
 * [545] Boundary of Binary Tree
 */
#include <bits/stdc++.h>

using std::vector;

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
    // T: O(n), n := the number of nodes
    // S: O(n) recursion stack
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root) {
            res.push_back(root->val);
            helper(root->left, true, false, res);
            helper(root->right, false, true, res);
        }
        return res;
    }

private:
    // 1. node->left is at left boundary if node is at left boundary; 
    //    node->right can also be at left boundary if node is at left 
    //    boundary and node->left is null
    // 2. similar rules for right boundary
    // 3. if node is at left boundary, add it before the children (preorder);
    //    if node is at right boundary, add it after the children (postorder)
    // 4. a leaf node that is at neither left nor right boundary belongs to the bottom
    void helper(TreeNode* node, bool lb, bool rb, vector<int>& res) {
        if (!node) return;
        if (lb) res.push_back(node->val);
        if (!lb && !rb && !node->left && !node->right) {
            res.push_back(node->val);
        }
        helper(node->left, lb, rb && !node->right, res);
        helper(node->right, lb && !node->left, rb, res);
        if (rb) res.push_back(node->val);
    }
};
// @lc code=end

