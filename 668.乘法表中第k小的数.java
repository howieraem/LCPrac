/*
 * @lc app=leetcode.cn id=668 lang=java
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
    // Similar to Q378.
    public int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;

        // Find the smallest element x (lower bound) such
        // that there are at least k elements less than or
        // equal to x in the multiplication table 
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (countSmaller(m, n, mid) < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    // Returns the number of elements on multiplication table 
    // smaller than mid
    private int countSmaller(int m, int n, int mid) {
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            cnt += Math.min(n, mid / i);
        }
        return cnt;
    }
}
// @lc code=end

