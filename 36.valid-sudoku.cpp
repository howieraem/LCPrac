/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2), n := 9
    // S: O(n ^ 2)
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row_freq(9, vector<int>(9, 0)),
                col_freq(9, vector<int>(9, 0)),
                subbox_freq(9, vector<int>(9, 0));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                const char& c = board[i][j];
                if (c != '.') {
                    int digit_idx = c - '0' - 1;  // convert to 0-indexed
                    int k = 3 * (i / 3) + j / 3;  // subbox's index
                    ++row_freq[i][digit_idx];
                    ++col_freq[j][digit_idx];
                    ++subbox_freq[k][digit_idx];
                    if (row_freq[i][digit_idx] > 1 || col_freq[j][digit_idx] > 1 || subbox_freq[k][digit_idx] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

