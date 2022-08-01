/**
 * Given a matrix, matrix[i][j] is the pixel value at (i, j). 0 is white and 1 is black.
 * The greyness at (i, j) is the difference between, the number of black pixels in the i-th
 * row and the j-th column, and the number of white pixels in the i-th row and the j-th 
 * column. Find the max greyness of the matrix.
 */
#include <algorithm>
#include <vector>

using std::vector;

// T: O(m * n)
// S: O(m + n)
int max_greyness(const vector<vector<int>>& mat) {
    const size_t m = mat.size(), n = mat[0].size();
    vector<int> row_sum(m), col_sum(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1) {
                ++row_sum[i];
                ++col_sum[j];
            } else {
                --row_sum[i];
                --col_sum[j];
            }
        }
    }
    return *std::max_element(row_sum.begin(), row_sum.end()) + 
            *std::max_element(col_sum.begin(), col_sum.end());
}
