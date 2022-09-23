/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */
#include <climits>

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
    // Pre-order traversal
    int helper(TreeNode* node, int cur_max) {
        if (node == nullptr) return 0;
        int ans = 0;
        if (node->val >= cur_max) {
            ++ans;
            cur_max = node->val;
        }
        ans += helper(node->left, cur_max);
        ans += helper(node->right, cur_max);
        return ans;
    }

public:
    // T: O(n)
    // S: O(n) worst case, linked list
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};
// @lc code=end

