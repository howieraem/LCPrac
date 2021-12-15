/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    // T: O(N), N := the number of nodes
    // S: O(1) (C/C++ tail recursion)
    void recoverTree(TreeNode* root) {
        n1 = nullptr;
        n2 = nullptr;
        pre = nullptr;

        traverse(root);
        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }

private:
    TreeNode *n1, *n2, *pre;

    // Inorder traversal that finds the problematic pair of nodes
    void traverse(TreeNode* node) {
        if (!node)  return;
        traverse(node->left);

        if (pre) {
            if (node->val < pre->val) {
                n2 = node;
                if (!n1) {
                    n1 = pre;
                }
            }
        }
        // if (!n1 && (!pre || node->val < pre->val)){
        //     n1 = pre;
        // }
        // if (n1 && node->val < pre->val){
        //     n2 = node;
        // }
        pre = node;

        traverse(node->right);
    }
};
// @lc code=end

