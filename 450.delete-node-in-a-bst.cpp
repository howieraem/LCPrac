/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    // Recursive
    // T: O(n)
    // S: O(n) recursion stack
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->val) {
            // search for target
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // search for target
            root->right = deleteNode(root->right, key);
        } else {
            // found target

            // If one child is null, return the other one.
            // This "virtually" deletes the current node.
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            }

            // If neither null, need to find the minimum node on the right child, 
            // replace current node's value with that min value, and delete the 
            // duplicate min value in the right branch.
            TreeNode* min_node = root->right;
            while (min_node->left != nullptr) {
                min_node = min_node->left;
            }
            root->val = min_node->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
    */

    // Iterative
    // Need an auxiliary pointer pre
    // T: O(n)
    // S: O(1)
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* pre = nullptr;
        TreeNode* cur = root;

        while (cur != nullptr && cur->val != key) {
            pre = cur;
            if (key < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        if (pre == nullptr) {
            // root is target
            return deleteNode(cur);
        }
        if (pre->left == cur) {
            pre->left = deleteNode(cur);
        } else {
            pre->right = deleteNode(cur);
        }
        return root;
    }

private:
    TreeNode* deleteNode(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        // If one child is null, return the other one.
        // This "virtually" deletes the current node.
        if (root->left == nullptr) {
            return root->right;
        }
        if (root->right == nullptr) {
            return root->left;
        }

        // If neither null, need to find the minimum node on the right child, 
        // and move the left branch of the current node to min node's left.
        TreeNode* min_node = root->right;
        while (min_node->left != nullptr) {
            min_node = min_node->left;
        }
        min_node->left = root->left;
        return root->right;
    }
};
// @lc code=end

