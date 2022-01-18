/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    /*
    // Solution 1
    // T: O(n1 + n2)
    // S: O(1)
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)  return nullptr;
        int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
        TreeNode* node = new TreeNode(val);

        node->left = mergeTrees(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        node->right = mergeTrees(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
        return node;
    }
    */

    // Solution 2
    // T: O(n1 + n2)
    // S: O(1)
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1)  return root2;
        if (!root2)  return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
// @lc code=end

