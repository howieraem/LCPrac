/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */
#include <vector>

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
    // Approach 1: level-order traversal (BFS), record the last node of each layer
    // Approach 2: DFS below
    // T: O(n), n := the number of nodes
    // S: O(n)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int depth, vector<int>& res) {
        if (!node) return;
        if (depth == res.size()) {
            res.push_back(node->val);
        }
        ++depth;
        // Not a standard pre-order traversal, as the right child is visited first.
        // If visit the left child first, the result becomes the left side view.
        dfs(node->right, depth, res);
        dfs(node->left, depth, res);
    }
};
// @lc code=end

