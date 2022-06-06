/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
    static constexpr int dx[] {-1, 0, 1, -1, 1, -1, 0, 1},
                         dy[] {-1, -1, -1, 0, 0, 1, 1, 1};

public:
    // T: O(m * n)
    // S: O(1)
    void gameOfLife(vector<vector<int>>& board) {
        // For each board element, use the 2nd bit to mark 
        // its next state. The 1st bit is equivalent to the 
        // original state (either 0 or 1).
        const int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;

                for (int d = 0; d < 8; ++d) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        sum += (board[ni][nj] & 0b01);
                    }
                }

                if (board[i][j] == 1 && (sum == 2 || sum == 3)) {
                    board[i][j] |= 0b10;    // next state is alive
                    // If sum > 3, next state is dead, the 2nd bit is still 0
                } else if (!board[i][j] && sum == 3) {
                    board[i][j] |= 0b10;
                }
            }
        }

        // Overwrite the 1st bit with the 2nd bit
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
// @lc code=end

