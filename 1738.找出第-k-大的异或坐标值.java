import java.util.PriorityQueue;

/*
 * @lc app=leetcode.cn id=1738 lang=java
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;

        // sum[i][j] means the XOR sum of elements from matrix[0:i][0:j]
        int[][] sum = new int[m + 1][n + 1];

        // Make the PQ a max heap instead of a min heap (i.e. originally `(a, b) -> b - a`)
        PriorityQueue<Integer> q = new PriorityQueue<>(k, (a, b) -> a - b);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = sum[i - 1][j] ^ sum[i][j - 1] ^ sum[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                if (q.size() < k) {
                    q.add(sum[i][j]);
                } else {
                    // poll only if current sum > heap top
                    if (sum[i][j] > q.peek()) {
                        q.poll();
                        q.add(sum[i][j]);
                    }
                }
            }
        }
        return q.peek();
    }
}
// @lc code=end

