/*
 * @lc app=leetcode.cn id=1310 lang=java
 *
 * [1310] 子数组异或查询
 */

// @lc code=start
class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        // prefix XOR
        int n = arr.length;
        int[] xors = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            xors[i + 1] = xors[i] ^ arr[i];
        }

        int m = queries.length;
        int[] res = new int[m];
        for (int i = 0; i < m; ++i) {
            res[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }
        return res;
    }
}
// @lc code=end

