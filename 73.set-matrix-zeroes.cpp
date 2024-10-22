/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size(); 
        const int n = matrix[0].size();
        bool col_zero_flag = false; 
        bool row_zero_flag = false;
        // Check if 1st row contains zero
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                row_zero_flag = true;
                break;
            }
        }
        // Check if 1st col contains zero
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col_zero_flag = true;
                break;
            }
        }

        // Use 1st row and 1st col to store whether the corresponding 
        // cols/rows should be zeroed (with the bool flags, information 
        // not lost)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    // if (i == 0) {
                    //     row_zero_flag = true;
                    // }
                    // if (j == 0) {
                    //     col_zero_flag = true;
                    // }
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // Process cells except 1st row and 1st col
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Process 1st row and 1st col
        if (row_zero_flag) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col_zero_flag) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end

