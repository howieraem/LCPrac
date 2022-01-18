/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */
#include <vector>

using std::vector;

// @lc code=start
class NumMatrix {
    vector<vector<int>> psum;  // S: O(m*n)

public:
    // T: O(m*n)
    NumMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        psum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] - psum[i][j] + matrix[i][j];
            }
        }
    }
    
    // T: O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        return psum[row2 + 1][col2 + 1] - psum[row2 + 1][col1] - psum[row1][col2 + 1] + psum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

