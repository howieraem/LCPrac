/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */
#include <bits/stdc++.h>

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
// S: O(n)
class BSTIterator {
public:
    // T: O(n)
    BSTIterator(TreeNode* root) {
        push_fn(root);
    }
    
    // T: O(n)
    int next() {
        if (st.empty()) {
            return -1;
        }

        TreeNode* cur = st.top(); st.pop();

        // In-order
        push_fn(cur->right);

        /*
        // Pre-order
        push_fn(cur->right);
        push_fn(cur->left);
        */

        /*
        // Post-order
        if (!st.empty() && cur == st.top()->left) {
            push_fn(st.top()->right);
        }
        */

        return cur->val;
    }
    
    // T: O(1)
    bool hasNext() {
        return !st.empty();
    }

private:
    std::stack<TreeNode*> st;

    void push_fn(TreeNode* root) {
        // In-order
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }

        /*
        // Pre-order
        if (root != nullptr) {
            st.push(root);
        }
        */

        /*
        // Post-order
        while (root != nullptr) {
            st.push(root);
            if (root->left != nullptr) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        */
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

