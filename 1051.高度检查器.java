/*
 * @lc app=leetcode.cn id=1051 lang=java
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
    public int heightChecker(int[] heights) {
        // given the constraints in hint, the approach can be based on bucket sort
        int[] arr = new int[101];
        for (int h : heights) {
            ++arr[h];
        }
        int cnt = 0;
        for (int i = 1, j = 0; i < 101; ++i) {
            while (arr[i]-- > 0) {
                if (heights[j++] != i)  ++cnt;
            }
        }
        return cnt;
    }
}
// @lc code=end

