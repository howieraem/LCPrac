/*
 * @lc app=leetcode.cn id=365 lang=java
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution {
    // Given a * jug1 + b * jug2 = target, check if integer solutions a and b exist
    // The answer is to find the greatest common divisor.
    // T: O(log(max(jug1, jug2)))
    // S: O(1) 
    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity)  return false;
        if (jug1Capacity == 0 || jug2Capacity == 0) {
            return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
        }

        // 当且仅当 z 是 x 和 y 的最大公约数的倍数时, a*x + b*y = z 有解，a、b可为负数。
        // 例如 a < 0 时的操作：
        //  1. 往 y 壶倒水；
        //  2. 把 y 壶的水倒入 x 壶；
        //  3. 如果 y 壶不为空，那么 x 壶肯定是满的，把 x 壶倒空，然后再把 y 壶的水倒入 x 壶。
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }

    private int gcd(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
}
// @lc code=end

