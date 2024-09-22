/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2)
    // S: O(n)
    int numTrees(int n) {
        // Given 1...n, suppose root is i, the left subtree 
        // should contain 1...(i - 1) and the right subtree 
        // should contain (i + 1)...n. If we build trees like 
        // this recursively, let dp[n] be the number of unique 
        // subtrees with 1...n, then dp[0] = dp[1] = 1, and 
        // dp[i] = sum(dp[j - 1] * dp[i - j] for j in [1...i])
        // with j being the subtree's root value.
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;  // dp[0] could mean just one null node
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

