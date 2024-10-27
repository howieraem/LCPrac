/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        // Note: assuming node values are unique
        unordered_map<int, int> inorder_value_to_idx;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_value_to_idx[inorder[i]] = i;
        }
        return helper(preorder, inorder_value_to_idx, 
                      0, preorder.size() - 1, 
                      0);
    }

private:
    // Reconstruct the tree with pre-order traversal + two pointers
    TreeNode* helper(
            const vector<int>& preorder, 
            const unordered_map<int, int>& inorder_value_to_idx, 
            int l_pre, int r_pre, int l_in) {
        if (l_pre > r_pre) {
            return nullptr;
        }

        int root_val = preorder[l_pre];
        int root_idx_inorder = inorder_value_to_idx.at(root_val);  // can't use operator[] for const unordered_map
        int left_subtree_sz = root_idx_inorder - l_in;
        
        TreeNode* root = new TreeNode(root_val);
        root->left = helper(preorder, inorder_value_to_idx, 
                            l_pre + 1, l_pre + left_subtree_sz,
                            l_in);
        root->right = helper(preorder, inorder_value_to_idx,
                             l_pre + left_subtree_sz + 1, r_pre, 
                             root_idx_inorder + 1);
        return root;
    }
};
// @lc code=end

