/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // It turns out res[i][j] equals iCj (the number of combinations of 
    // j items sampled from i items without replacement). Thus, this is
    // an nice approach to compute the number of combinations without
    // overflow.
    // T: O(numRows ^ 2)
    // S: O(numRows ^ 2)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i) {
            res[i] = vector<int>(i + 1);
            res[i].front() = 1;
            res[i].back() = 1;

            // Update numbers between the first and the last elements of ith row.
            // Note that when i = 0 (base case) the following will not run.
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};
// @lc code=end

