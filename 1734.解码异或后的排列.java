/*
 * @lc app=leetcode.cn id=1734 lang=java
 *
 * [1734] 解码异或后的排列
 */

// @lc code=start
class Solution {
    public int[] decode(int[] encoded) {
        // From Question 1720, x ^ y = z -> x = y ^ z. However,
        // this question does not provide the first/last 
        // element of perm. Thus, we need to find it.
        int n = encoded.length + 1;

        // 求得除了 perm[n - 1] 以外所有 perm 元素的异或结果，每隔一位做异或运算
        int a = 0;
        for (int i = 0; i < n - 1; i += 2) {
            a ^= encoded[i];
        }

        // 求得所有 perm 元素的异或结果，perm 为 [1 ... n] 的一种排列
        int b = 0;
        for (int i = 1; i <= n; ++i) {
            b ^= i;
        }

        // 求得 perm[n - 1] 后，从后往前解码
        int[] perm = new int[n];
        perm[n - 1] = a ^ b;    // a ^ perm[n - 1] = b
        for (int i = n - 2; i >= 0; --i) {
            perm[i] = encoded[i] ^ perm[i + 1];
        }
        return perm;
    }
}
// @lc code=end

