/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */
#include <bits/stdc++.h>

using std::unordered_map;

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
    // DFS + prefix sums to avoid the O(n ^ 2) "nested" recursion solution
    // T: O(n), n := no. of nodes
    // S: O(n)
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix_sum_freq;
        prefix_sum_freq[0LL] = 1;  // IMPORTANT: base case, for paths starting from the root
        return dfs(root, 0LL, prefix_sum_freq, targetSum);
    }

private:
    int dfs(TreeNode* root, long long cur_sum, unordered_map<long long, int>& prefix_sum_freq, const int& target) {
        if (root == nullptr) {
            return 0;
        }
        
        // cur_sum is the sum of path from root to current node.
        // The sum from any node in the middle of the path to the current node 
        // equals the diff between the sum from the root to the current node 
        // and the prefix sum of the node in the middle
        cur_sum += root->val;
        int ans = 0;
        auto it = prefix_sum_freq.find(cur_sum - target);  // like two-sum
        if (it != prefix_sum_freq.end()) {
            ans = it->second;
        }

        ++prefix_sum_freq[cur_sum];   // IMPORTANT: incr after checking diff
        ans += dfs(root->left, cur_sum, prefix_sum_freq, target);
        ans += dfs(root->right, cur_sum, prefix_sum_freq, target);
        --prefix_sum_freq[cur_sum];   // like backtracking
        return ans;
    }
};
// @lc code=end

