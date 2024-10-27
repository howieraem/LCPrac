/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */
#include <bits/stdc++.h>

using std::unordered_map;
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
    // Why do we need two traversal results to reconstruct? 
    // Because neither results indicate null nodes.
    // T: O(n)
    // S: O(n)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Note: assuming node values are unique
        unordered_map<int, int> inorder_value_to_idx;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_value_to_idx[inorder[i]] = i;
        }
        return helper(inorder_value_to_idx, postorder, 
                      0, inorder.size() - 1, 
                      0, postorder.size() - 1);
    }

private:
    // Reconstruct the tree with pre-order traversal + two pointers
    TreeNode* helper(
            const unordered_map<int, int>& inorder_value_to_idx, 
            const vector<int>& postorder, 
            int l_in, int r_in, 
            int l_post, int r_post) {
        if (l_in > r_in) {
            return nullptr;
        }
        int root_val = postorder[r_post];
        int root_idx_inorder = inorder_value_to_idx.at(root_val);  // can't use operator[] for const unordered_map
        int left_subtree_sz = root_idx_inorder - l_in;

        TreeNode* root = new TreeNode(root_val);
        root->left = helper(inorder_value_to_idx, postorder,
                            l_in, root_idx_inorder - 1,
                            l_post, l_post + left_subtree_sz - 1);
        root->right = helper(inorder_value_to_idx, postorder, 
                             root_idx_inorder + 1, r_in,
                             l_post + left_subtree_sz, r_post - 1);
        return root;
    }
};
// @lc code=end

