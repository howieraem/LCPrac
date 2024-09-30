/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(max(r, c) ^ 2)
    // S: O(1) excl. output
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int tot = rows * cols;
        vector<vector<int>> res(tot, vector<int>(2));
        int r = rStart; 
        int c = cStart;
        res[0][0] = r;
        res[0][1] = c;
        int dx = 0;
        int dy = 1;
        int p = 1;
        int dirn_dist = 0;

        while (p < tot) {
            for (int i = 0; i < (dirn_dist >> 1) + 1; ++i) {
                r += dx;
                c += dy;
                if (0 <= r && r < rows && 0 <= c && c < cols) {
                    res[p][0] = r;
                    res[p][1] = c;
                    ++p;
                }
            }
            // switch direction (0, 1) -> (1, 0) -> (0, -1) -> (-1, 0) -> ...
            int tmp = dx;
            dx = dy;
            dy = -tmp;
            ++dirn_dist; // travel distance seq: 1, 1, 2, 2, 3, 3, ...
        }
        return res;
    }
};
// @lc code=end

