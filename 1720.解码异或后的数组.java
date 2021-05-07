/*
 * @lc app=leetcode.cn id=1720 lang=java
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution {
    /**
     * encoded[i - 1] = res[i - 1] ^ res[i]
     * ->
     * encoded[i - 1] ^ res[i - 1] = res[i - 1] ^ res[i] ^ res[i - 1]
     * ->
     * encoded[i - 1] ^ res[i - 1] = res[i] ^ 0
     * ->
     * res[i] = encoded[i - 1] ^ res[i - 1]
     */
    public int[] decode(int[] encoded, int first) {
        int n = encoded.length + 1;
        int[] res = new int[n];
        res[0] = first;
        for (int i = 1; i < n; ++i) {
            res[i] = encoded[i - 1] ^ res[i - 1];
        }
        return res;
    }
}
// @lc code=end

