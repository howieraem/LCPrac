/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2)
    // S: O(1)
    void rotate(vector<vector<int>>& matrix) {
        /*
        Given 2D rotation matrix R: [x', y'].T = R [x, y].T

        90 deg clockwise = -pi/2 rad, R = [[0, 1], [-1, 0]]
        180 deg = pi rad, R = [[-1, 0], [0, -1]]
        90 deg anticlockwise = pi/2 rad, R = [[0, -1], [1, 0]]
        */
        int n = matrix.size(), half = n >> 1;
        for (int i = 0; i < half; ++i) {
            for (int j = 0; j < n - half; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};
// @lc code=end

