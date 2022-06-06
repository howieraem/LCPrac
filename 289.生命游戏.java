/*
 * @lc app=leetcode.cn id=289 lang=java
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
    public void gameOfLife(int[][] board) {
        final int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
        final int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};

        for (int i = 0; i < board.length; ++i) {
            for (int j = 0 ; j < board[0].length; ++j) {
                int sum = 0;
                for (int k = 0; k < 8; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length) {
                        sum += (board[nx][ny] & 0b01);  // 只累加最低位
                    }
                }

                // 使用第二个bit标记是否存活(2 = 0b10)
                if (board[i][j] == 1) {
                    if (sum == 2 || sum == 3) {
                        board[i][j] |= 0b10;
                    }
                    // sum大于3时第二个bit仍为0，下一状态为死亡
                } else {
                    if (sum == 3) {
                        board[i][j] |= 0b10;
                    }
                }
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                board[i][j] >>= 1;  // 右移一位，用第二bit覆盖第一个bit
            }
        }
    }
}
// @lc code=end

