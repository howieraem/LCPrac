/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Advanced two pointers
    // T: O(n ^ 2)
    // S: O(1) ignoring output
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;

        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; ++j) {
                res[top][j] = x++;
            }

            for (int i = top + 1; i <= bottom; ++i) {
                res[i][right] = x++;
            }

            if (left < right && top < bottom) {
                for (int j = right - 1; j > left; --j) {
                    res[bottom][j] = x++;
                }

                for (int i = bottom; i > top; --i) {
                    res[i][left] = x++;
                }
            }
            
            ++left;
            --right;
            ++top;
            --bottom;
        }

        return res;
    }
};
// @lc code=end

