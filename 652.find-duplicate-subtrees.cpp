/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::string;
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
    // T: O(n ^ 2) if full serialization, O(n) if serializing with id
    // S: O(n)
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        // unordered_map<string, int> subtree_cnts;
        // traverse(root, subtree_cnts, res);
        unordered_map<int, int> subtree_cnts; 
        unordered_map<string, int> serial2id;
        int cur_id = 1;
        traverse(root, subtree_cnts, serial2id, cur_id, res);
        return res;
    }

private:
    /*
    // T: O(n ^ 2)
    string traverse(TreeNode* node, unordered_map<string, int>& subtree_cnts, vector<TreeNode*>& res) {
        if (!node) return "#";
        auto left = traverse(node->left, subtree_cnts, res);
        auto right = traverse(node->right, subtree_cnts, res);
        auto serialized = left + "," + right + "," + std::to_string(node->val);  // this line is O(n)

        // increment count, and only record one instance of the duplicate subtree
        if (++subtree_cnts[serialized] == 2) {
            res.push_back(node);
        }
        return serialized;
    }
    */

    // T: O(n)
    int traverse(TreeNode* node, unordered_map<int, int>& subtree_cnts, unordered_map<string, int>& serial2id, int& cur_id, vector<TreeNode*>& res) {
        if (node == nullptr) {
            return 0;
        }
        int left = traverse(node->left, subtree_cnts, serial2id, cur_id, res);
        int right = traverse(node->right, subtree_cnts, serial2id, cur_id, res);

        auto serialized = std::to_string(left) + "," + std::to_string(node->val) + "," + std::to_string(right);
        int sid;
        auto it = serial2id.find(serialized);
        if (it == serial2id.end()) {
            sid = ++cur_id;
            serial2id[serialized] = sid;
        } else {
            sid = it->second;
        }
        
        if (++subtree_cnts[sid] == 2) {
            res.push_back(node);
        }
        return sid;
    }
};
// @lc code=end

