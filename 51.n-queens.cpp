/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // backtracking
    // T: O(n * n!)
    // S: O(n)
    // Complexity analysis see https://leetcode.com/problems/n-queens/discuss/1551695
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        // For checking availabilities of columns, 45-deg diagonals and 135-deg diagonals
        const int n_diags = (n << 1) - 1;
        bool avail_col[n], avail_diag[n_diags], avail_antidiag[n_diags];  // avoid using vector<bool>
        fill_n(avail_col, n, true);
        fill_n(avail_diag, n_diags, true);
        fill_n(avail_antidiag, n_diags, true);

        backtrack(res, board, avail_col, avail_diag, avail_antidiag, 0, n);
        return res;
    }

private:
    static void backtrack(
            vector<vector<string>> &res, vector<string> &board, 
            bool *avail_col, bool *avail_diag, bool *avail_antidiag, 
            int row, const int &n) {
        if (row == n) {
            // reached bottom of board
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            int diag_idx = row + col;
            int antidiag_idx = n - 1 - row + col;

            // queen can be placed at current (row, col)
            if (avail_col[col] && avail_diag[diag_idx] && avail_antidiag[antidiag_idx]) {
                avail_col[col] = avail_diag[diag_idx] = avail_antidiag[antidiag_idx] = false;
                board[row][col] = 'Q';

                // DFS
                backtrack(res, board, avail_col, avail_diag, avail_antidiag, row + 1, n);

                // Undo
                avail_col[col] = avail_diag[diag_idx] = avail_antidiag[antidiag_idx] = true;
                board[row][col] = '.';
            }
        }
    }
};
// @lc code=end

