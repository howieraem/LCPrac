/*
 * @lc app=leetcode.cn id=1578 lang=java
 *
 * [1578] 避免重复字母的最小删除成本
 */

// @lc code=start
class Solution {
    public int minCost(String s, int[] cost) {
        int ans = 0;
        char[] a = s.toCharArray();
        for (int i = 1; i < s.length(); ++i) {
            if (a[i] == a[i - 1]) {
                if (cost[i - 1] > cost[i]) {
                    ans += cost[i];
                    // keep the greater cost and overwrite 
                    // the cost of the deleted char
                    cost[i] = cost[i - 1];
                } else {
                    ans += cost[i - 1];
                }
            }
        }
        return ans;
    }
}
// @lc code=end

