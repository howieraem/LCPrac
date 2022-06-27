/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::string;
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
    // T: O(n)
    // S: O(n)
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtree_cnts;
        vector<TreeNode*> res;
        traverse(root, subtree_cnts, res);
        return res;
    }

private:
    string traverse(TreeNode* node, unordered_map<string, int>& subtree_cnts, vector<TreeNode*>& res) {
        if (!node) return "#";
        auto left = traverse(node->left, subtree_cnts, res),
             right = traverse(node->right, subtree_cnts, res);
        auto serialized = left + "," + right + "," + std::to_string(node->val);

        // increment count, and only record one instance of the duplicate subtree
        if (++subtree_cnts[serialized] == 2) {
            res.push_back(node);
        }
        return serialized;
    }
};
// @lc code=end

