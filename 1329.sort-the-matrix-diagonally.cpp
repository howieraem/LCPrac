/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */
#include <bits/stdc++.h>

using std::greater;
using std::priority_queue;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // Heap + 2D matrix traversal + hash map
    // T: O(m * n * log(min(m, n)))
    // S: O(m * n)
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int m = mat.size();
        if (m == 0) {
            return mat;
        }
        const int n = mat[0].size();
        if (n == 0) {
            return mat;
        }

        // k: diagonal idx, v: min heap of diagonal values
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diagonal_vals;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int d_idx = i - j;
                diagonal_vals[d_idx].push(mat[i][j]);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int d_idx = i - j;
                auto pq_it = diagonal_vals.find(d_idx);
                // if (pq_it == diagonal_vals.end()) {
                //     // this shouldn't happen
                //     continue;
                // }
                mat[i][j] = pq_it->second.top(); pq_it->second.pop();
            }
        }
        return mat;
    }
};
// @lc code=end

