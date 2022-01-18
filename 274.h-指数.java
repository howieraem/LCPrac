import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=274 lang=java
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n = citations.length, cnt = 0;
        while (cnt < n && citations[n - cnt - 1] > cnt)  ++cnt;
        return cnt;
    }
}
// @lc code=end

