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
    // T: O(n)
    // S: O(n) recursion stack worst case
    string serialize(TreeNode* root) {
        // Pre-order traversal
        string res;
        build_str(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    // T: O(n)
    // S: O(n)
    TreeNode* deserialize(string data) {
        // extract nodes (incl. null)
        queue<string> q;
        string tmp;
        for (const auto& c : data) {
            if (c == ',') {
                // A new node or subtree
                q.push(std::move(tmp));
                // tmp.clear();
                continue;
            }
            tmp.push_back(c);
        }
        q.push(std::move(tmp));  // don't forget the last one
        
        return build_tree(q);
    }

private:
    void build_str(TreeNode* node, string& res) {
        if (node == nullptr) {
            res.push_back('X');
            return;
        }

        // Pre-order traversal
        res.append(to_string(node->val)).push_back(',');
        build_str(node->left, res);
        res.push_back(',');  // IMPORTANT separate subtrees
        build_str(node->right, res);
    }

    TreeNode* build_tree(queue<string>& q) {
        // Pre-order traversal
        const string val = q.front(); q.pop();
        if (val == "X") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = build_tree(q);
        node->right = build_tree(q);
        return node;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

