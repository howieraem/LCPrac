/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1
    // T: O(query_row ^ 2)
    // S: O(query_row)
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur_row(1, poured);

        for (int i = 0; i <= query_row; ++i) {
            vector<double> next_row(i + 2, 0);

            for (int j = 0; j <= i; ++j) {
                if (cur_row[j] > 1) {
                    double dif = (cur_row[j] - 1) / 2.;
                    next_row[j] += dif;
                    next_row[j + 1] += dif;
                    cur_row[j] = 1;
                }
            }

            if (i != query_row) {
                cur_row = next_row;
            }
        }

        return cur_row[query_glass];
    }
    */

    // Solution 2 (slightly optimized)
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur_row(query_row + 1);
        cur_row[0] = poured;
        for (int i = 0; i < query_row; ++i) {

            // Reverse iterations to prevent overwriting prerequisite data
            for (int j = i; j >= 0; --j) {
                double dif = std::max(0., cur_row[j] - 1) / 2.;
                if (j + 1 <= query_row) {
                    cur_row[j + 1] += dif;
                }
                cur_row[j] = dif;
            }
        }
        return cur_row[query_glass] >= 1. ? 1. : cur_row[query_glass];
    }
};
// @lc code=end

