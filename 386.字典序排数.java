/*
 * @lc app=leetcode.cn id=386 lang=java
 *
 * [386] 字典序排数
 */
import java.util.List;
import java.util.ArrayList;


// @lc code=start
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, res);
        }
        return res;
    }

    private void dfs(int i, int n, List<Integer> res) {
        // pre-order traversal of a 10-branch tree
        if (i > n)  return;
        res.add(i);
        for (int j = 0; j <= 9; ++j) {
            dfs(i * 10 + j, n, res);
        }
    }
}
// @lc code=end

