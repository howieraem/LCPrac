/*
 * @lc app=leetcode id=873 lang=java
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
class Solution {
    // 2D DP + two sum + two pointers
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    public int lenLongestFibSubseq(int[] arr) {
        final int n = arr.length;
        
        // Find the longest fib-like subseq (ignoring the leading two elements)
        // dp[l][r] means the length of such a subseq that ends with arr[l] and arr[r]
        int[][] dp = new int[n][n];
        int maxLen = -1;

        for (int i = 2; i < n; ++i) {
            // We can use two pointers because arr is sorted
            int l = 0;
            int r = i - 1;
            
            while (l < r) {
                int sum = arr[l] + arr[r];
                if (sum == arr[i]) {
                    // l < r < i && arr[l] + arr[r] = arr[i]
                    dp[r][i] = dp[l][r] + 1;
                    maxLen = Math.max(maxLen, dp[r][i]);
                    ++l;
                    --r;
                } else if (sum > arr[i]) {
                    --r;
                } else {  // sum < arr[i]
                    ++l;
                }
            }
        }

        // return 0 if no eligible fib-like subseq (min. len 3) exists
        return maxLen == -1 ? 0 : maxLen + 2;

        /* 
           If arr is not sorted, we can use a hashmap to track the index of arr values 
           and apply two sum approach to check index of the diff value 
        */
        // int ans = 0;
        // Map<Integer, Integer> val2idx = new HashMap<>();
        // for (int j = 0; j < A.length; j++) {
        //     val2idx.put(A[j], j);
        //     for (int i = 0; i < j; i++) {
        //         int k = val2idx.getOrDefault(A[j] - A[i], -1);
        //         dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
        //         ans = Math.max(ans, dp[i][j]);
        //     }
        // }
        // return ans > 2 ? ans : 0;
    }
}
// @lc code=end

