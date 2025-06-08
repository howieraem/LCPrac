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
// Intuitive approach: check if is same tree for each node in full tree. T: O(m * n), S: O(m + n).

// Optimal approach 1: serialize the trees, and check if the subtree is a substring.
// T: O(m + n) ignoring std::to_string(node->val)
// S: O(m + n)
class Solution {
    // Pre-order traversal
    // T: O(n)
    // S: O(n)
    void serialize(TreeNode* root, string& s) {
        if (root == nullptr) {
            s.push_back('#');
            return;
        }

        s.push_back(',');
        s.append(std::to_string(root->val));
        serialize(root->left, s);
        serialize(root->right, s);
    }

    // Check if t is a substring of s with KMP
    bool is_substring(const string& s, const string& t) {
        const int n = t.size();

        if (n > s.size()) {
            // prune
            return false;
        }

        // construct the lps array
        vector<int> lps(n, 0);
        int i = 1; 
        int j = 0;
        while (i < n) {
            // compute for t[i:j+1]
            if (t[i] == t[j]) {
                lps[i++] = ++j;
                // lps[i] = j + 1; i++; j++;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                // lps[i] = 0;
                ++i;
            }
        }
        
        i = j = 0;
        while (i < s.size()) {
            if (s[i] == t[j]) {
                if (j == n - 1) {
                    return true;
                } else {
                    ++i; 
                    ++j;
                }
            } else {
                if (j > 0) { 
                    j = lps[j - 1];
                } else {
                    ++i;
                }
            }
        }
        return false;
    }

public:
    // DFS + KMP
    // T: O(m + n)
    // S: O(m + n)
    // Better than recursively checking isSameTree which will take O(m * n)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string tree1;
        string tree2;
        serialize(root, tree1);
        serialize(subRoot, tree2);
        // return tree1.find(tree2) != string::npos;  // std implementation is not KMP
        return is_substring(tree1, tree2);
    }
};

// Optimal approach 2: Merkle hashing, hash subtree at every node in root's tree, 
// and check if the hashed subRoot's tree is in the hash set.
// @lc code=end

