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
// The in-order traversal result of a BST is sorted
class Solution {
public:
    /* 
    // Recursive in-order traversal + two pointers
    // T: O(N), N := the number of nodes
    // S: O(N)
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return isValidBST(root, pre);
    }

    static bool isValidBST(TreeNode* cur, TreeNode* pre) {
        if (cur == nullptr) {
            return true;
        }
        if (!isValidBST(cur->left, pre)) {
            return false;
        }
        if (pre != nullptr && pre->val >= cur->val) {
            return false;
        }
        pre = cur;
        return isValidBST(cur->right, pre);
    }
    */

    // Iterative in-order traversal + two pointers
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
            if (pre != nullptr && pre->val >= root->val) {
                return false;
            }
            pre = root;
            // End of the visit logic in in-order traversal
            
            root = root->right;
        }
        return true;
    }
};
// @lc code=end

