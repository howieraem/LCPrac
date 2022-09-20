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

    private static void backtrack(StringBuilder path, int nL, int nR, List<String> res) {
        if (nL > nR) return;
        if (nL == 0 && nR == 0) {
            res.add(path.toString());
            return;
        }

        if (nL > 0) {
            path.append('(');
            backtrack(path, nL - 1, nR, res);
            path.deleteCharAt(path.length() - 1);
        }

        if (nR > 0) {
            path.append(')');
            backtrack(path, nL, nR - 1, res);
            path.deleteCharAt(path.length() - 1);
        }
    }
}
// @lc code=end

