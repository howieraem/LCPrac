/*
 * @lc app=leetcode id=250 lang=cpp
 *
 * [250] Count Univalue Subtrees
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
public:
    // T: O(n)
    // S: O(1)
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }

private:
    static bool helper(TreeNode* root, int &ans) {
        if (!root)  return true;
        bool left = helper(root->left, ans),
             right = helper(root->right, ans);
        if (left && 
            right && 
            ((!root->left || root->left->val == root->val)) && 
            ((!root->right || root->right->val == root->val))) {
            ++ans;
            return true;
        }
        return false;
    }
};
// @lc code=end

