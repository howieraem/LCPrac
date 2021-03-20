/*
 * @lc app=leetcode.cn id=118 lang=java
 *
 * [118] 杨辉三角
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        if (numRows < 1)  return res;
        List<Integer> first = new ArrayList<>();
        first.add(1);
        res.add(first);
        for (int i = 1; i < numRows; ++i) {
            List<Integer> cur = new ArrayList<>(), pre = res.get(i-1);
            cur.add(1);
            for (int j = 1; j < i; ++j) {
                cur.add(pre.get(j-1)+pre.get(j));
            }
            cur.add(1);
            res.add(cur);
        }
        return res;
    }
}
// @lc code=end

