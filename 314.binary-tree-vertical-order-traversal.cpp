/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
 */
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

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
    // BFS solution. 
    // T: O(n)
    // S: O(n)
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        
        unordered_map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        int min_col = 0, max_col = 0;
        while (q.size()) {
            auto &[node, col] = q.front();
            mp[col].push_back(node->val);

            if (node->left) {
                q.push({node->left, col - 1});
                min_col = min(min_col, col - 1);
            }

            if (node->right) {
                q.push({node->right, col + 1});
                max_col = max(max_col, col + 1);
            }
            q.pop();
        }

        for (int i = min_col; i <= max_col; ++i) {
            res.push_back(mp[i]);
        }
        return res;
    }
    // Note that DFS solution exists but its time complexity is O(n * log(n)).
    // https://leetcode.com/problems/binary-tree-vertical-order-traversal/discuss/668240
};
// @lc code=end

