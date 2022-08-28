/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */

// @lc code=start
class Solution {
public:
    // T: O(N), N := 3
    // S: O(N)
    bool validTicTacToe(const vector<string>& board) {
        int turns = 0;
        int rows[3] {}, cols[3] {};
        int diag = 0, antidiag = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    ++turns;
                    ++rows[i];
                    ++cols[j];
                    diag += (i == j);
                    antidiag += (i + j == 2);
                } else if (board[i][j] == 'O') {
                    --turns;
                    --rows[i];
                    --cols[j];
                    diag -= (i == j);
                    antidiag -= (i + j == 2);
                }
            }
        }

        bool x_win = rows[0] == 3 || rows[1] == 3 || rows[2] == 3 || 
               cols[0] == 3 || cols[1] == 3 || cols[2] == 3 || 
               diag == 3 || antidiag == 3;
        bool o_win = rows[0] == -3 || rows[1] == -3 || rows[2] == -3 || 
               cols[0] == -3 || cols[1] == -3 || cols[2] == -3 || 
               diag == -3 || antidiag == -3;
        
        // check if the game is finished and valid
        if ((x_win && turns != 1) || (o_win && turns != 0)) return false;
        
        // check if the ongoing game is valid
        return turns == 1 || turns == 0;
    }
};
// @lc code=end

