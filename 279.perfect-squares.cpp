/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // 1D DP, like knapsack problem
    // T: O(n * sqrt(n))
    // S: O(n)
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }

        // dp[i] is the least number of perfect square numbers summing to i.
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }

    /*
    // BFS
    // T: O(n ^ (h / 2))
    // S: O(sqrt(n) ^ h)
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        std::queue<int> q;
        std::unordered_set<int> vis;
        q.emplace(0);
        vis.insert(0);

        int depth = 0;
        while (!q.empty()) {
            int sz = q.size();
            ++depth;
            while (sz-- > 0) {
                int x = q.front(); q.pop();
                for (int i = 1; x + i * i <= n; ++i) {
                    int v = x + i * i;
                    if (v == n) {
                        return depth;
                    }
                    if (vis.find(v) == vis.end()) {
                        q.emplace(v);
                        vis.insert(v);
                    }
                }
            }
        }
        return depth;
    }
    */
};
// @lc code=end

