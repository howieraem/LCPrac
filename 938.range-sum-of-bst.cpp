/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    void helper(TreeNode* root, int l, int r, int &ans) {
        if (!root)  return;
        int x = root->val;
        if (x >= l && x <= r) {
            ans += x;
        }
        if (x > l)  helper(root->left, l, r, ans);
        if (x < r)  helper(root->right, l, r, ans);
    }

public:
    // T: O(n)
    // S: O(n)
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        helper(root, low, high, ans);
        return ans;
    }
};
// @lc code=end

