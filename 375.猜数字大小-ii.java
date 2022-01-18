import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=375 lang=java
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
    // public int getMoneyAmount(int n) {
    //     /* Minimax又名极小化极大算法问题，需要通过获取局部最大值计算全局最小值。 */
    //     int[][] dp = new int[n + 1][n + 1];
    //     // dp meaning: minimum cost to win for interval [i, j]
    //     // base case: when i == j, cost is 0.
    //     // so start the length from 2.
    //     for (int length = 2; length <= n; ++length) {
    //         for (int start = 1; start <= n - length + 1; ++start) {
    //             int min = Integer.MAX_VALUE;
    //             for (int pivot = start + (length - 1) / 2; pivot < start + length - 1; ++pivot) {
    //                 // Always make the first choice on the right of the pivot, 
    //                 // which costs more than choosing the pivot's left side.
    //                 int res = pivot + Math.max(dp[start][pivot - 1], dp[pivot + 1][start + length - 1]);
    //                 min = Math.min(res, min);
    //             }
    //             dp[start][start + length - 1] = min;
    //         }
    //     }
    //     return dp[1][n];
    // }

    public int getMoneyAmount(int n) {
        Map<String, Integer> mem = new HashMap<>();
        return calc(1, n, mem);
    }

    private int calc(int l, int r, Map<String, Integer> mem) {
        if (l >= r)  return 0;
        if (l + 1 == r)  return l;
        String k = Integer.toString(l) + '-' + Integer.toString(r);
        if (mem.containsKey(k))  return mem.get(k);
        int min = Integer.MAX_VALUE;
        for (int pivot = l + (r - l) / 2; pivot <= r; ++pivot) {
            // Always make the first choice on the right of the pivot, 
            // which costs more than choosing the pivot's left side.
            min = Math.min(min, pivot + Math.max(calc(l, pivot - 1, mem), calc(pivot + 1, r, mem)));
        }
        mem.put(k, min);
        return min;
    }
}
// @lc code=end

