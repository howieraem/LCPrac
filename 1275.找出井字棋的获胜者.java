/*
 * @lc app=leetcode.cn id=1275 lang=java
 *
 * [1275] 找出井字棋的获胜者
 */

// @lc code=start
class Solution {
    private static final int[] WINS = {
        0b111000000,
        0b000111000,
        0b000000111,
        0b100100100,
        0b010010010,
        0b001001001,
        0b100010001,
        0b001010100,
    };

    public String tictactoe(int[][] moves) {
        int a = 0, b = 0;
        for (int i = 0; i < moves.length; ++i) {
            int cellIdx = moves[i][0] * 3 + moves[i][1];
            if ((i & 1) == 0) {
                // A moves
                a |= (1 << cellIdx);
            } else {
                // B moves
                b |= (1 << cellIdx);
            }
        }

        for (int win : WINS) {
            if ((a & win) == win)  return "A";
            else if ((b & win) == win)  return "B";
        }

        if ((a | b) == 0b111111111)  return "Draw";
        return "Pending";
    }
}
// @lc code=end

