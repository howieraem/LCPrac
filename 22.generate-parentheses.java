/*
 * @lc app=leetcode id=22 lang=java
 *
 * [22] Generate Parentheses
 */
import java.util.*;

// @lc code=start
class Solution {
    // T: O(2 ^ (2n)) as there are 2 recursive calls in backtrack() and it requires 2n steps to get one result
    // S: O(n) max depth of recursion
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrack(new StringBuilder(), n, n, res);
        return res;
    }

    private static void backtrack(StringBuilder path, int remainL, int remainR, List<String> res) {
        if (remainL > remainR) {
            // This is necessary, because we want a left parenthesis to appear in front of
            // its corresponding right parenthesis. Without this, results will contain
            // things like ")))((("
            return;
        }
        if (remainL == 0 && remainR == 0) {
            res.add(path.toString());
            return;
        }

        if (remainL > 0) {
            path.append('(');
            backtrack(path, remainL - 1, remainR, res);
            path.deleteCharAt(path.length() - 1);
        }

        if (remainR > 0) {
            path.append(')');
            backtrack(path, remainL, remainR - 1, res);
            path.deleteCharAt(path.length() - 1);
        }
    }
}
// @lc code=end

