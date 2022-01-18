import java.util.*;

/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    private List<String> res;

    public List<String> generateParenthesis(int n) {
        res = new ArrayList<>();
        backtrack("", n, n);
        return res;
    }

    private void backtrack(String track, int remain_left, int remain_right) {
        if (
            remain_left < 0 ||          // no remaining left parethese
            remain_right < 0 ||         // no remaining right parethese
            remain_left > remain_right  // no. of right parethese is more, invalid
        )  return;  
        if (remain_left == 0 && remain_right == 0) {
            res.add(track.toString());
            return;
        }

        // Do backtracking twice, for a left parenthesis and a right parenthesis respectively:
        // track.append("(")
        // backtrack(track, remain_left - 1, remain_right)
        // track.pop()
        // track.append(")")
        // backtrack(track, remain_left, remain_right - 1)
        // track.pop()
        backtrack(track + "(", remain_left - 1, remain_right);
        backtrack(track + ")", remain_left, remain_right - 1);
    }
}
// @lc code=end

