/*
 * @lc app=leetcode id=2128 lang=cpp
 *
 * [2128] Remove All Ones With Row and Column Flips
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(n)
    bool removeOnes(vector<vector<int>>& grid) {
        const int M = grid.size(), N = grid[0].size();

        // Only possible if each row has the same "pattern",
        // e.g. flipping some of the rows will make all rows 
        // the same. For example, 001100 and 110011 have the 
        // same pattern. When all rows are the same, we can 
        // just flip the columns with all ones.
        vector<int> flipped_row0 = grid[0];
        for (int j = 0; j < N; ++j) {
            flipped_row0[j] = 1 - flipped_row0[j];
        }

        for (int i = 1; i < M; ++i) {
            if (grid[i] != grid[0] && grid[i] != flipped_row0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

