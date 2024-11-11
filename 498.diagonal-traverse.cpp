/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // matrix traversal + geometry + advanced two pointers
    // T: O(m * n)
    // S: O(1)
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const auto m = mat.size(); 
        const auto n = mat[0].size();
        const auto total = m * n;
        vector<int> res(total);

        int i = 0;
        int j = 0;
        for (int p = 0; p < total; ++p) {
            res[p] = mat[i][j];
            if ((i + j) & 1) {     // i + j is odd, direction is downward
                if (i == m - 1) {
                    ++j;      // last row, go right
                } else if (j == 0) {
                    ++i;      // first column and non-last row, go down
                } else {         
                    // go down and left        
                    ++i;
                    --j;
                }
            } else {    // i + j is even, direction is upward
                if (j == n - 1) {
                    ++i;      // last column, go down
                } else if (i == 0) {
                    ++j;      // first row and non-last column, go right
                } else {   
                    // go up and right
                    --i; 
                    ++j;
                }
            }
        }
        return res;
    }

    // follow-up: no zig zag, matrix may be jugged. Q1424
};
// @lc code=end

