/*
 * @lc app=leetcode.cn id=1888 lang=java
 *
 * [1888] 使二进制字符串字符交替的最少反转次数
 */

// @lc code=start
/**
 * 1. 类型 1 和 类型 2 的操作顺序与最终答案无关，只与操作次数有关
 * 2. 按照 "01" 模式检测时需要修改的次数，用 n 减去就是按照 "10" 模式检测时修改的次数
 * 3. 类型 1 的操作，其实是头尾相接，但是先删除再添加操作开销太大，并且操作很麻烦
 * 4. 将字符串复制一份接在后面，即可使用滑动窗口丝滑拼接
 * 5. 滑窗时减去离开的格子，加上进来的格子，即可避免大量重复计算
 * 6. 答案就是滑窗过程中出现的最小修改次数
 * 7. 实现时可以通过索引取模来模拟字符串复制拼接在后，不需要真的复制和拼接
 */
class Solution {
    private static final char[] PATTERN = new char[]{'0', '1'};

    public int minFlips(String s) {
        int n = s.length(), flips = 0;
        char[] a = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            if (a[i] != PATTERN[i & 1])  ++flips;
        }

        // Update the result as either `flips` or `n - flips`.
        // If `flips` is taken, then the target string will look
        // like "010101...", otherwise "101010...". 
        int ans = Math.min(flips, n - flips);
        if ((n & 1) == 0)  return ans;  // When `n` is even, operation 1 is useless
        for (int i = 0; i < n; ++i) {
            // Sliding window with a fixed size n on a virtual
            // "doubled" string, i.e. the string `s` is copied
            // and paste to its right.
            if (a[i] != PATTERN[i & 1])  --flips;
            if (a[i] != PATTERN[(i + n) & 1])  ++flips;
            ans = Math.min(ans, Math.min(flips, n - flips));
        }
        return ans;
    }
}
// @lc code=end

