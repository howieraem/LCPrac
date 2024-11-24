/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
        int ans = 0;
        helper(root, ans);
        return ans;
    }

private:
    // Post-order traversal + 1D DP
    // T: O(n)
    // S: O(n) recursion stack
    int helper(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return 0;
        }

        int l_longest_path = helper(root->left, ans);
        int r_longest_path = helper(root->right, ans);
        
        // The longest path may not pass through parent node
        ans = max(l_longest_path + r_longest_path, ans);
        return max(l_longest_path, r_longest_path) + 1;
    }
};
// @lc code=end

