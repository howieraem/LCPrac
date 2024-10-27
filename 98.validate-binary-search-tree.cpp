/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */
#include <bits/stdc++.h>

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
    /* 
    // Recursive pre-order traversal approach
    // T: O(N), N := the number of nodes
    // S: O(N)
    bool isValidBST(TreeNode* root) {
        // Had to use long extrema to handle INT_MIN and INT_MAX in test cases.
        // Better to record the current minimum and maximum nodes instead.
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    static bool isValidBST(TreeNode* root, long min, long max) {
        if (!root)  return true;
        if ((root->val <= min) || (root->val >= max)) {
            return false;
        }
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    */

    // Iterative in-order traversal approach: the in-order traversal result of a BST is sorted.
    // T: O(N), N := the number of nodes
    // S: O(N)
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        std::stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            
            // The visit logic in in-order traversal
            root = stk.top(); stk.pop();
            if (pre != nullptr && root->val <= pre->val) {
                return false;
            }
            pre = root;
            // The visit logic in in-order traversal
            
            root = root->right;
        }
        return true;
    }
};
// @lc code=end

