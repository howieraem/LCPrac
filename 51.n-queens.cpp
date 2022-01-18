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
    // T: O(n * n!)
    // S: O(n)
    // Complexity explanation see https://leetcode.com/problems/n-queens/discuss/1551695
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        // For checking availabilities of columns, 45-deg diagonals and 135-deg diagonals
        const int n_diags = (n << 1) - 1;
        bool avail_col[n], avail_diag1[n_diags], avail_diag2[n_diags];  // avoid using vector<bool>
        fill_n(avail_col, n, true);
        fill_n(avail_diag1, n_diags, true);
        fill_n(avail_diag2, n_diags, true);

        backtrack(res, board, avail_col, avail_diag1, avail_diag2, 0, n);
        return res;
    }

private:
    static void backtrack(
        vector<vector<string>> &res, vector<string> &board, bool avail_col[], bool avail_diag1[], bool avail_diag2[], int row, const int &n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (avail_col[col] && avail_diag1[row + col] && avail_diag2[n - 1 - row + col]) {
                avail_col[col] = avail_diag1[row + col] = avail_diag2[n - 1 - row + col] = false;
                board[row][col] = 'Q';

                // DFS
                backtrack(res, board, avail_col, avail_diag1, avail_diag2, row + 1, n);

                // Undo
                board[row][col] = '.';
                avail_col[col] = avail_diag1[row + col] = avail_diag2[n - 1 - row + col] = true;
            }
        }
    }
};
// @lc code=end

