/*
 * @lc app=leetcode id=1605 lang=cpp
 *
 * [1605] Find Valid Matrix Given Row and Column Sums
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(1) excl. the output
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // each entry must be limited by the smaller sum associated
                res[i][j] = std::min(rowSum[i], colSum[j]);

                // take the maximum possible entry value each time, and subtract 
                // it from both sums, so that the constraint sum(rowSum) == sum(colSum)
                // never breaks
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

