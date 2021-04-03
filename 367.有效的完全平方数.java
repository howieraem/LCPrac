/*
 * @lc app=leetcode.cn id=367 lang=java
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
    public boolean isPerfectSquare(int num) {
        if (num < 2)  return true;
        int left = 2, right = num / 2, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid == num / mid && num % mid == 0) {
                // condition same as `mid ^ 2 == num` but prevents Integer overflow
                return true;
            }
            if (mid > num / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

    // public boolean isPerfectSquare(int num) {
    //     if (num < 2)  return true;
    //     int x = num / 2;
    //     while (x > num / x) {   // same as x * x > num but prevents Integer overflow
    //         x = (x + num / x) / 2;
    //     }
    //     return (x == num / x && num % x == 0);  // same as x * x == num but prevents Integer overflow
    // }
}
// @lc code=end

