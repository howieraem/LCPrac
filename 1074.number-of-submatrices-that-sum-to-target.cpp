/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // Advanced prefix sum + two sum
    // T: O(m ^ 2 * n)
    // S: O(m * n)
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int sum[m + 1][n + 1];
        std::memset(sum, 0, sizeof(sum));
        // Get prefix sums
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int ans = 0;

        // Below is 2D-version of Q560
        unordered_map<int, int> mp;
        for (int i = 1; i <= m; ++i) {
            for (int j = i; j <= m; ++j) {
                // Accumulate per column
                for (int k = 1; k <= n; ++k) {
                    int cur = sum[j][k] - sum[i - 1][k];
                    ans += (cur == target);
                    auto it = mp.find(cur - target);
                    if (it != mp.end()) {
                        ans += it->second;
                    }
                    ++mp[cur];
                }

                mp.clear();  // IMPORTANT
            }
        }
        return ans;
    }
};
// @lc code=end

