/*
 * @lc app=leetcode.cn id=1486 lang=java
 *
 * [1486] 数组异或操作
 */

// @lc code=start
class Solution {
    // public int xorOperation(int n, int start) {
    //     int ans = start;
    //     for (int i = 1; i < n; ++i) {
    //         start += 2;
    //         ans ^= start;
    //     }
    //     return ans;
    // }

    int calc(int x) {
        // 4*i ^ (4*i + 1) ^ (4*i + 2) ^ (4*i + 3) = 0
        if (x % 4 == 0) return x;
        else if (x % 4 == 1) return 1;
        else if (x % 4 == 2) return x + 1;
        else return 0;
    }

    public int xorOperation(int n, int start) {
        // 整体除以 2，利用 %4 结论计算除「最低一位」的结果
        int s = start >> 1;
        // 计算 1 到 s - 1 的异或结果，再计算 1 到 s + n - 1 的异或结果，两者异或得到除最后一位的结果
        int prefix = calc(s - 1) ^ calc(s + n - 1);
        // 利用「奇偶性」计算的「最低一位」
        int last = n & start & 1;
        return prefix << 1 | last;
    }
}
// @lc code=end

