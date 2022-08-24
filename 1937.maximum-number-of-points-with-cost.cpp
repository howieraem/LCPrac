/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(n)
    long long maxPoints(vector<vector<int>>& points) {
        const int M = points.size(), N = points[0].size();
        vector<long long> dp(N);
        // Init with the 1st row
        for (int j = 0; j < N; ++j) {
            dp[j] = points[0][j];
        }

        // From the 2nd row onwards, scan from left to right and 
        // from right to left to determine maximum scores gained.
        for (int i = 1; i < M; ++i) {
            vector<long long> left(N, 0);
            left[0] = dp[0];
            for (int j = 1; j < N; ++j) {
                // Choose between "move left" and "keep cur. col."
                left[j] = std::max(left[j - 1] - 1, dp[j]);
            }

            vector<long long> right(N, 0);
            right[N - 1] = dp[N - 1];
            for (int j = N - 2; j >= 0; --j) {
                // Choose between "move right" and "keep cur. col."
                right[j] = std::max(right[j + 1] - 1, dp[j]);
            }

            vector<long long> cur(N, 0);
            for (int j = 0; j < N; ++j) {
                cur[j] = points[i][j] + std::max(left[j], right[j]);
            }
            dp = cur;
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

