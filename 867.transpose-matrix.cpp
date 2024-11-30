/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(1) excl. output
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

