import java.util.*;

/*
 * @lc app=leetcode.cn id=216 lang=java
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
    private List<List<Integer>> res;
    private Stack<Integer> path;

    public List<List<Integer>> combinationSum3(int k, int n) {
        res = new ArrayList<>();
        path = new Stack<>();
        backtrack(n, k, 0, 1);
        return res;
    }

    private void backtrack(int n, int k, int curSum, int startIdx) {
        if (curSum > n) {
            return;
        }
        if (path.size() == k) {
            if (curSum == n)  res.add(new ArrayList<>(path));
            return;
        }
        for (int i = startIdx; i <= 9 - (k - path.size()) + 1; ++i) {
            curSum += i;
            path.push(i);
            backtrack(n, k, curSum, i + 1);
            curSum -= i;
            path.pop();
        }
    }
}
// @lc code=end

