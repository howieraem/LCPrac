/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

#include <string>
#include <vector>

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
// Intuitive approach: check if is same tree for each node in full tree. T: O(m * n)

// Optimal approach: serialize the trees, and check if the subtree is a substring.
// T: O(m + n) ignoring std::to_string(node->val)
// S: O(m + n)
class Solution {
    // Pre-order traversal
    void serialize(TreeNode* root, string& s) {
        if (root == nullptr) {
            s.append(",#");
        } else {
            s.append(",");
            s.append(std::to_string(root->val));
            serialize(root->left, s);
            serialize(root->right, s);
        }
    }

    // Check if t is a substring of s
    bool kmp(const string& s, const string& t) {
        const int m = s.size(), n = t.size();

        // construct the lps array
        int j = 0;
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            while (j > 0 && t[i] != t[j]) {
                j = lps[j - 1];
            }
            if (t[i] == t[j]) {
                ++j;
                lps[i] = j;
            }
        }

        j = 0;
        for (int i = 0; i < m; ++i) {
            while (j > 0 && s[i] != t[j]) {
                j = lps[j - 1];
            }
            if (s[i] == t[j]) {
                ++j;
                if (j == n) return true;
            }
        }
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string tree1, tree2;
        serialize(root, tree1);
        serialize(subRoot, tree2);
        // return tree1.find(tree2) != string::npos;  // std implementation is not KMP
        return kmp(tree1, tree2);
    }
};
// @lc code=end

