/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */
#include <bits/stdc++.h>

using std::vector;
using std::max;

// @lc code=start
class Solution {
public:
    /*
    // 2D DP (bottom-up)
    // T: O(n ^ 3)
    // S: O(n ^ 2)
    int maxCoins(vector<int>& nums) {
        // Pad with 1 to avoid complicated logics dealing with edge cases
        vector<int> balloons;
        balloons.reserve(nums.size() + 2);
        balloons.push_back(1);
        for (const int &num : nums) {
            if (num != 0) {  // skip the zeros
                balloons.push_back(num);
            }
        }
        balloons.push_back(1);
        const int n = balloons.size();

        // dp[i][j] means the maximum coins achievable by bursting 
        // all balloons in (i, j), i and j NOT included
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for (int k = 2; k < n; ++k) { // length of the interval
            for (int left = 0; left < n - k; ++left) { // interval left bound
                int right = left + k; // interval right bound
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(
                        dp[left][right],  // don't burst at i
                        balloons[left] * balloons[i] * balloons[right] + dp[left][i] + dp[i][right]);  // burst at i
                }
            }
        }
        return dp[0][n - 1];
    }
    */
    
    // Memoized DFS (top-down 2D DP)
    // T: O(n ^ 3)
    // S: O(n ^ 2)
    int maxCoins(vector<int>& nums) {
        // Pad with 1 to avoid complicated logics dealing with edge cases
        vector<int> balloons;
        balloons.reserve(nums.size() + 2);
        balloons.push_back(1);
        for (const int &num : nums) {
            if (num != 0) {  // skip the zeros
                balloons.push_back(num);
            }
        }
        balloons.push_back(1);
        const int n = balloons.size();

        vector<vector<int>> memo(n, vector<int>(n, 0));
        return dfs(balloons, memo, 0, n - 1);
    }

    // There are O(n ^ 2) memo states. Calculating each memo state takes O(n).
    // IMPORTANT: dfs(..., l, r) does not involve bursting balloons[l] and balloons[r]
    int dfs(const vector<int>& balloons, vector<vector<int>>& memo, int l, int r) {
        if (l + 1 == r) {
            // search done, no balloons to be bursted between l and r
            return 0;
        }
        if (memo[l][r] != 0) {
            // state visited, reuse
            return memo[l][r];
        }
        for (int i = l + 1; i < r; ++i) {  
            memo[l][r] = max(
                    memo[l][r], 
                    balloons[l] * balloons[i] * balloons[r] + 
                        dfs(balloons, memo, l, i) + 
                        dfs(balloons, memo, i, r));
        }
        return memo[l][r];
    }
};
// @lc code=end

