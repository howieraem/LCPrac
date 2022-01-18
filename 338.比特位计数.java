/*
 * @lc app=leetcode.cn id=338 lang=java
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num+1];
        for (int i = 0; i <= num; ++i) {
            if (i % 2 == 1)  {
                res[i] = res[i - 1] + 1;
            } else {
                res[i] = res[i / 2];
            }
        }
        return res;
    }
}
// @lc code=end

