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
    // Matrix + Counter
    // T: O(n ^ 2), n := 9
    // S: O(n ^ 2)
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row_freq(9, vector<int>(9, 0));
        vector<vector<int>> col_freq(9, vector<int>(9, 0));
        vector<vector<int>> subbox_freq(9, vector<int>(9, 0));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                const char& c = board[i][j];
                if (c != '.') {
                    int digit_idx = c - '0' - 1;  // convert to 0-indexed

                    // subbox's index, both i and j divided by 3 first, then mult new row index 
                    // by 3 because 2D flattened to 1D (avoid using a 3D vector)
                    int k = 3 * (i / 3) + j / 3;
                    
                    if (++row_freq[i][digit_idx] > 1 || ++col_freq[j][digit_idx] > 1 || ++subbox_freq[k][digit_idx] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

