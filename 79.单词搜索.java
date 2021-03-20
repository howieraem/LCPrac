/*
 * @lc app=leetcode.cn id=79 lang=java
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
    private int n, l, lw;

    public boolean exist(char[][] board, String word) {
        n = board[0].length;
        l = board.length*n;
        lw = word.length() - 1;
        for (int i = 0; i < l; ++i) {
            if (backtrack(board, word, i, 0))  return true;
        }
        return false;
    }

    private boolean backtrack(char[][] b, String w, int idx, int charIdx) {
        int r = idx / n, c = idx % n;
        char tmp = b[r][c];
        if (tmp != w.charAt(charIdx))  return false;
        if (charIdx == lw)  return true;
        b[r][c] = 0;
        charIdx++;
        if (
            ((idx+1) % n != 0 && backtrack(b, w, idx+1, charIdx)) ||    // left
            (idx % n != 0 && backtrack(b, w, idx-1, charIdx)) ||        // right
            (idx + n < l && backtrack(b, w, idx+n, charIdx)) ||         // down
            (idx >= n && backtrack(b, w, idx-n, charIdx))               // up
        )  return true;
        b[r][c] = tmp;
        return false;
    }
}

// @lc code=end

