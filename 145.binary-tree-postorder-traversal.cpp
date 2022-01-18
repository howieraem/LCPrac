/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */
#include <stack>
#include <vector>

using std::stack;
using std::vector;

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
    // Version 1
    // T: O(n)
    // S: O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)  return res;
        stack<TreeNode*> s;
        s.push(root);
        while (s.size()) {
            const auto node = s.top();

            // If a nullptr is encountered,
            // all children have been visited.
            if (!node) {
                s.pop();
                res.push_back(s.top()->val);
                s.pop();
                continue;
            }

            // Use a nullptr to mark parent node
            s.push(nullptr);

            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }
        return res;
    }
    */

    // Version 2
    // T: O(n)
    // S: O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)  return res;
        stack<TreeNode*> s;
        TreeNode* last = nullptr;

        while (root || s.size()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode* node = s.top();
                if (node->right && last != node->right) {
                    root = node->right;
                } else {
                    res.push_back(node->val);
                    last = node;
                    s.pop();
                }
            }
        }
        return res;
    }
};
// @lc code=end

