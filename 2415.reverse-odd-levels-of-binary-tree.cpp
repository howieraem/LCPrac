#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int lvl = 0;

public:
    // T: O(n)
    // S: O(n) recursion stack
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        helper(root->left, root->right, 1);
        return root;
    }

private:
    void helper(TreeNode* l, TreeNode* r, int lvl) {
        if (l == nullptr || r == nullptr) {
            return;
        }
        if (lvl & 1) {
            std::swap(l->val, r->val);
        }
        ++lvl;
        helper(l->left, r->right, lvl);
        helper(l->right, r->left, lvl);
    }
};