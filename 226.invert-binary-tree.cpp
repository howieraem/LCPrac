/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    // T: O(n)
    // S: O(log(n))
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        // Either pre-order or post-order will work
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        // std::swap(root->left, root->right);

        return root;
    }

    /*
    // Iterative solution
    // T: O(n)
    // S: O(log(n))
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        std::stack<TreeNode*> st;  // can also use a queue (becomes BFS)
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if (node->left != nullptr) {
                st.push(node->left);
            }
            if (node->right != nullptr) {
                st.push(node->right);
            }
        }
        return root;
    }
    */
};
// @lc code=end

