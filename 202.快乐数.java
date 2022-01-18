/*
 * @lc app=leetcode.cn id=202 lang=java
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
    public boolean isHappy(int n) {
        // similar strategy to q141: find loop in linked list
        int slow = n, fast = getNxt(n);
        while (fast != 1 && slow != fast) {
            slow = getNxt(slow);
            fast = getNxt(getNxt(fast));
        }
        return fast == 1;
    }

    private int getNxt(int n) {
        int tot = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            tot += d * d;
        }
        return tot;
    }
}
// @lc code=end

