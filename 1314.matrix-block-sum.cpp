/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(m * n)
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        const int m = mat.size(), n = mat[0].size();
        int preSum[m + 1][n + 1];
        memset(preSum, 0, sizeof(preSum));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int r1 = max(0, i - k),
                    c1 = max(0, j - k),
                    r2 = min(i + k + 1, m),
                    c2 = min(j + k + 1, n);
                res[i][j] = preSum[r2][c2] - preSum[r2][c1] - preSum[r1][c2] + preSum[r1][c1];
            }
        }
        return res;
    }
};
// @lc code=end

