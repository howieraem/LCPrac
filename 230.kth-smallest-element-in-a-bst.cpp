/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */
#include <stack>

using std::stack;

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
    // The result of in-order traversal of a BST is sorted.

    /*
    // Recursive version
    // T: O(k)
    // S: O(k)
    int kthSmallest(TreeNode* root, int& k) {
        if (root == nullptr) {
            return -1;  // Constraint: node->val >= 0
        }
        
        int x = kthSmallest(root->left, k);
        if (k == 0) {
            // Early stop/prune: k already becomes 0 while visiting left subtree
            return x;
        }

        if (--k == 0) {
            return root->val; // k becomes 0 at current node
        }

        // continue visit right subtree
        return kthSmallest(root->right, k); 
    }
    */

    // Iterative version
    // T: O(k)
    // S: O(k)
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }   
            
            // The visit logic in in-order traversal
            root = stk.top(); stk.pop();
            if (--k == 0) {
                break;
            }
            // End of the visit logic in in-order traversal

            root = root->right;
        }
        return root->val;
    }
};
// @lc code=end

