/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    void traverse(
            TreeNode* root, 
            int r, 
            int c, 
            std::unordered_map<int, std::map<int, int>>& mp, 
            int& min_col, 
            int& max_col) {
        if (!root)  return;
        min_col = std::min(min_col, c);
        max_col = std::max(max_col, c);

        // Multiple nodes can have the same row and column. Elements in each column should be ordered by 
        // row and then by value (if same row). As the range of node value is [0, 1000], we can encode row 
        // and node together. If the range of node value is unknown, we should use std::multiset, see: 
        // https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/260502/ (change 
        // std::set in both BFS and DFS solutions to std::multiset as nodes at the same location can have
        // the same value, and record min_col and max_col instead).
        int k = r * 10000 + root->val;
        ++mp[c][k];

        ++r;
        traverse(root->left, r, c - 1, mp, min_col, max_col);
        traverse(root->right, r, c + 1, mp, min_col, max_col);
    }

public:
    // T: O(n * log(n)), n := the number of tree nodes
    // S: O(n)
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        std::unordered_map<int, std::map<int, int>> mp;  // col_id => row_id => val
        int min_col = 0, max_col = 0;
        traverse(root, 0, 0, mp, min_col, max_col);

        std::vector<std::vector<int>> res;
        for (int c = min_col; c <= max_col; ++c) {
            std::vector<int> col_res;
            for (const auto &row_p : mp[c]) {
                int val = row_p.first % 10000;
                for (int i = 0; i < row_p.second; ++i) {
                    col_res.push_back(val);
                }
            }
            res.push_back(col_res);
        }
        return res;
    }
};
// @lc code=end

