/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * n!)
    // S: O(n)
    // Complexity explanation see https://leetcode.com/problems/n-queens/discuss/1551695
    int totalNQueens(int n) {
        int ans = 0;

        // For checking availabilities of columns, 45-deg diagonals and 135-deg diagonals
        const int n_diags = (n << 1) - 1;
        bool avail_col[n], avail_diag1[n_diags], avail_diag2[n_diags];  // avoid using vector<bool>
        fill_n(avail_col, n, true);
        fill_n(avail_diag1, n_diags, true);
        fill_n(avail_diag2, n_diags, true);

        backtrack(ans, avail_col, avail_diag1, avail_diag2, 0, n);
        return ans;
    }

private:
    static void backtrack(
        int &ans, bool avail_col[], bool avail_diag1[], bool avail_diag2[], int row, const int &n) {
        if (row == n) {
            ++ans;
            return;
        }
        for (int col = 0; col < n; ++col) {
            int diag_idx = row + col;
            int antidiag_idx = n - 1 - row + col;
            if (avail_col[col] && avail_diag1[diag_idx] && avail_diag2[antidiag_idx]) {
                avail_col[col] = avail_diag1[diag_idx] = avail_diag2[antidiag_idx] = false;

                // DFS
                backtrack(ans, avail_col, avail_diag1, avail_diag2, row + 1, n);

                // Undo
                avail_col[col] = avail_diag1[diag_idx] = avail_diag2[antidiag_idx] = true;
            }
        }
    }
};
// @lc code=end

