/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */
#include <algorithm>
#include <climits>

using std::max;

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
    // T: O(n), n := the number of nodes
    // S: O(n)
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

private:
    static int dfs(TreeNode* root, int &curMax) {
        if (!root)  return 0;
        int leftSum = dfs(root->left, curMax),
            rightSum = dfs(root->right, curMax);
        // Current path sum can include bath paths
        curMax = max(curMax, root->val + leftSum + rightSum);

        // Choose one of the subtrees (paths) for the next step
        return max(0, max(leftSum, rightSum) + root->val);
    }
};
// @lc code=end

