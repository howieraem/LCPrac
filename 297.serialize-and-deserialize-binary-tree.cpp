/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */
#include <string>
#include <queue>

using std::stoi;
using std::string;
using std::to_string;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)  return "X";
        // Pre-order traversal
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string tmp;
        for (const auto &c : data) {
            if (c == ',') {
                q.push(tmp);
                tmp.clear();
                continue;
            }
            tmp.push_back(c);
        }
        q.push(tmp);
        return helper(q);
    }

private:
    TreeNode* helper(queue<string> &q) {
        // Preorder traversal
        const string val = q.front(); q.pop();
        if (val == "X")  return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = helper(q);
        node->right = helper(q);
        return node;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

