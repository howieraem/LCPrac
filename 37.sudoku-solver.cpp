/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
    bool row[9][9];
    bool col[9][9];
    bool cube[3][3][9];

public:
    // Backtracking
    // T: O(9 ^ k), k := no. of unfilled cells
    // S: O(k) recursion stack
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(cube, false, sizeof(cube));

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int d = board[r][c] - '1';
                    row[r][d] = true;
                    col[c][d] = true;
                    cube[r / 3][c / 3][d] = true;
                }
            }
        }

        solve(board, 0, 0);
    }

private:
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) {
            return true;
        }
        if (j == 9) {
            // solve next row
            return solve(board, i + 1, 0);
        }
        if (board[i][j] != '.') {
            // skip and check next col
            return solve(board, i, j + 1);
        }

        for (int d = 0; d < 9; ++d) {
            int ci = i / 3;
            int cj = j / 3;
            if (row[i][d] || col[j][d] || cube[ci][cj][d]) {
                // digit already used
                continue;
            }
            board[i][j] = '1' + d;
            row[i][d] = col[j][d] = cube[ci][cj][d] = true;
            if (solve(board, i, j + 1)) {
                // if valid, return directly with modified board
                return true;
            }
            // undo
            board[i][j] = '.';
            row[i][d] = col[j][d] = cube[ci][cj][d] = false;
        }
        return false;  // none of combo under this branch worked
    }
};
// @lc code=end

