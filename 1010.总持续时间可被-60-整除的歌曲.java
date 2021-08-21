/*
 * @lc app=leetcode.cn id=1010 lang=java
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

// @lc code=start
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int ans = 0;
        int[] remainderCnt = new int[60];

        for (int t : time) {
            int r = t % 60;
            int targetR = r > 0 ? 60 - r : 0;
            ans += remainderCnt[targetR];
            ++remainderCnt[r]; 
        }
        return ans;
    }
}
// @lc code=end

