/*
 * @lc app=leetcode id=1878 lang=cpp
 *
 * [1878] Get Biggest Three Rhombus Sums in a Grid
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // sorted set + advanced matrix traversal (brute-force)
    // T: O(m * n * min(m, n) * log(k)), k := 3
    // S: O(k)
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return {};
        }
        const int K = 3;
        const int m = grid.size();
        const int n = grid[0].size();
        const int MAX_RHOMBUS_SZ = (std::min(m, n) >> 1) + 1;
        std::set<int> uniq_sums;

        // Single cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                uniq_sums.insert(grid[i][j]);
                if (uniq_sums.size() > K) {
                    // remove the current smallest sum
                    uniq_sums.erase(uniq_sums.begin());
                }
            }
        }

        // Rhombi
        for (int len = 1; len < MAX_RHOMBUS_SZ; ++len) {
            for (int r = len; r < m - len; ++r) {  // row
                for (int c = len; c < n - len; ++c) {  // col
                    int sum = 0;

                    // left to top side
                    int i = r;
                    int j = c - len;
                    while (j <= c) {
                        sum += grid[i--][j++];
                    }

                    // top to right side
                    i = r - len + 1;
                    j = c + 1;
                    while (i < r) {
                        sum += grid[i++][j++];
                    }

                    // right to bottom side
                    i = r;
                    j = c + len;
                    while (j >= c) {
                        sum += grid[i++][j--];
                    }

                    // bottom to left side
                    i = r + len - 1;
                    j = c - 1;
                    while (i > r) {
                        sum += grid[i--][j--];
                    }

                    uniq_sums.insert(sum);
                    if (uniq_sums.size() > K) {
                        // remove the current smallest sum
                        uniq_sums.erase(uniq_sums.begin());
                    }
                }
            }
        }

        // Order DESC
        return vector<int>(uniq_sums.rbegin(), uniq_sums.rend());
    }
};
// @lc code=end

