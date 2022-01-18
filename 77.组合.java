/*
 * @lc app=leetcode.cn id=77 lang=java
 *
 * [77] 组合
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        if (k <= 0 || n < k) return res;
        Stack<Integer> track = new Stack<>();
        backtrack(n, k, 1, track, res);
        return res;
    }

    private void backtrack(int n, int k, int start, Stack<Integer> track, List<List<Integer>> res) {
        if (track.size() == k) {
            res.add(new ArrayList<>(track));     // make a copy of current path
            return;
        }
        for (int i = start; i <= n; ++i) {
            track.push(i);
            backtrack(n, k, i + 1, track, res);
            track.pop();
        }
    }
}
// @lc code=end

