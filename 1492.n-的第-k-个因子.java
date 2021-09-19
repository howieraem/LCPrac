/*
 * @lc app=leetcode.cn id=1492 lang=java
 *
 * [1492] n 的第 k 个因子
 */

// @lc code=start
class Solution {
    public int kthFactor(int n, int k) {
        /* Time complexity O(n). */
        // int cnt = 0;
        // for (int i = 1; i <= n; ++i) {
        //     if (n % i == 0) {
        //         ++cnt;
        //         if (cnt == k)  return i;
        //     }
        // }
        // return -1;

        /* Optimized: If d is a factor of n, then n / d is also a factor of n.
           Time complexity O(sqrt(n)). */
        int i = 1;
        while (i * i <= n) {
            if ((n % i == 0) && --k == 0)  return i;
            ++i;
        }
        --i;    // undo the final iteration above to ensure i * i <= n

        if (i * i == n)  --i;   // i is double-counted

        // When i < sqrt(n), n / i > i, the ascending order remains. 
        // No need to collect and sort factors to obtain the kth factor.
        while (i >= 1) {
            if ((n % i == 0) && --k == 0)  return n / i;
            --i;
        }
        return -1;
    }
}
// @lc code=end

