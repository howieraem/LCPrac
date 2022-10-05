/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
    static constexpr int D[] {1, 0, -1, 0, 1};

public:
    // Idea: 'O's not connected (top, bottom, left or right) to the boundaries will be flipped to 'X'.
    // Incorporate a third char '#' to mark 'O's connected to the boundaries and distinguish from 'O's 
    // to be flipped.

    // T: O(m * n)
    // S: O(m * n)
    void solve(vector<vector<char>>& board) {
        const int m = board.size(), n = board[0].size();

        // Horizontal boundaries
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                dfs(board, i, 0, m, n);
            }

            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                dfs(board, i, n - 1, m, n);
            }
        }

        // Vertical boundaries
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                dfs(board, 0, j, m, n);
            }

            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                dfs(board, m - 1, j, m, n);
            }
        }

        // If a cell is a '#', then it was an 'O' not to be flipped.
        // If a cell is still an 'O' after DFS, then it's not connected 
        // to the boundaries and will be flipped.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c, const int& m, const int& n) {
        for (int d = 0; d < 4; ++d) {
            int nr = r + D[d], nc = c + D[d + 1];
            if (0 <= nr && nr < m && 0 <= nc && nc < n && board[nr][nc] == 'O') {
                board[nr][nc] = '#';
                dfs(board, nr, nc, m, n);
            }
        }
    }
};
// @lc code=end

