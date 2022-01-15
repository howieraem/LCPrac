/*
 * @lc app=leetcode.cn id=275 lang=java
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
    public int hIndex(int[] citations) {
        // Binary search is the most efficient when data is sorted
        int n = citations.length, l = 0, r = n - 1;
        while (l <= r) {
            int m = ((r - l) >> 1) + l;
            int h = n - m;
            if (citations[m] == h) {
                return h;
            } else if (citations[m] > h) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return n - l;
    }
}
// @lc code=end

