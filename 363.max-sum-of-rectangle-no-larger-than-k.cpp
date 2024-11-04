/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */
#include <bits/stdc++.h>

using std::set;
using std::vector;

// @lc code=start
class Solution {
public:
    // Prefix sum + Kadane's algo + binary search
    // As cells may contain non-positive numbers, cannot use 2D sliding window.
    // T: O(n ^ 2 * m * log(m)), assume m > n
    // S: O(m)
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MIN;

        for (int l = 0; l < n; ++l) {
            vector<int> row_prefix_sums(m);

            for (int r = l; r < n; ++r) {
                // Kadane's algorithm, get submatrix max sum (regardless of threshold k)
                int kadane_2d = 0;
                int max_kadane_2d = INT_MIN;
                for (int i = 0; i < m; ++i) {
                    row_prefix_sums[i] += matrix[i][r];
                    kadane_2d = std::max(kadane_2d + row_prefix_sums[i], row_prefix_sums[i]);
                    max_kadane_2d = std::max(max_kadane_2d, kadane_2d);
                }

                if (max_kadane_2d <= k) {
                    // largest submatrix's sum not exceeding k,
                    // prune further binary search
                    ans = std::max(ans, max_kadane_2d);
                    continue;
                }

                // else need to shrink submatrix
                set<int> s = {0};
                int prefix_sums_2d = 0;
                for (const int& row_prefix_sum : row_prefix_sums) {
                    prefix_sums_2d += row_prefix_sum;

                    // 2D submatrix sum is the diff of two prefix sums
                    // Binary search the largest submatrix sum <= prefix_sum_2d - k
                    auto it = s.lower_bound(prefix_sums_2d - k);
                    if (it != s.end()) {
                        ans = std::max(ans, prefix_sums_2d - *it);
                    }
                    s.insert(prefix_sums_2d);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

