/*
 * @lc app=leetcode.cn id=786 lang=java
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        double l = 0., r = 1.;
        // Initialize answer as 0/1 = 0 = l
        int p = 0, q = 1, n = arr.length;

        // Since binary search is on floating point,
        // better not to use conditions like l <= r
        // to break the loop. In this question,
        // checking count == k is sufficient.
        while (true) {
            double m = (l + r) * 0.5;
            int cnt = 0;
            p = 0;
            
            // Count the number of fractions smaller than m
            // with sliding window
            for (int i = 0, j = 0; j < n; ++j) {
                // while ((i < n) && (double) arr[i] / arr[j] < m)
                while (i < n && arr[i] * m < arr[j]) {
                    ++i;
                }
                cnt += n - i;
                if (i < n && p * arr[i] < q * arr[j]) {
                    // update answer when (double) arr[i]/arr[j] > (double) p/q
                    p = arr[j]; 
                    q = arr[i];
                }
            }

            if (cnt == k)  return new int[]{p, q};
            else if (cnt < k) {
                l = m;  // different from binary search on integers
            } else {
                r = m;  // different from binary search on integers
            }
        }
    }
}
// @lc code=end

