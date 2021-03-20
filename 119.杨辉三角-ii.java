/*
 * @lc app=leetcode.cn id=119 lang=java
 *
 * [119] 杨辉三角 II
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<Integer> getRow(int rowIndex) {
        // Use definition: at row n (starts from 0) of triangle, value at index i (starts from 0) is C(n, i).
        List<Integer> res = new ArrayList<>();
        res.add(1);
        for (int i = 1; i < rowIndex; ++i) {
            long ret = (long) res.get(i - 1) * (long) (rowIndex + 1 - i) / i;
            res.add((int) ret);
        }
        res.add(1);
        return res;
    }
}
// @lc code=end

