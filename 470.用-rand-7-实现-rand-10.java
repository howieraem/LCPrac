/*
 * @lc app=leetcode.cn id=470 lang=java
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    /**
     * 1. (randX() - 1) * Y + randY() 可以等概率生成 [1, X * Y] 范围的随机数
     * 2. 拒绝采样，尽量减少拒绝采样的次数（舍弃的数）
     * 3. 通过取模等操作把范围映射到所需范围
     */
    public int rand10() {
        // Can't do things like rand7() + rand7() directly 
        // because it does not uniformly generate a number
        // within the interval [1, 14], e.g. 2 + 3 == 3 + 2

        // Below uniformly generates number from 1 to 49 and then 
        // refuses sampling if the number is between 41 and 49 as
        // [41, 49] have less elements than [1, 10] 
        int ans;
        do {
            ans = (rand7() - 1) * 7 + rand7();
        } while (ans > 40);

        // Reduce and shift. Shifting is needed since `%` can produce 0.
        return 1 + (ans - 1) % 10;
    }
}
// @lc code=end

