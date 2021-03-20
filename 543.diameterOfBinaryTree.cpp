/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include <algorithm>

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        helper(root);
        return ans-1;
    }
private:
    int ans;
    int helper(TreeNode* root) {
        if (root == nullptr)  return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        ans = max(left + right + 1, ans);
        return max(left, right) + 1;
    }
};
// @lc code=end

