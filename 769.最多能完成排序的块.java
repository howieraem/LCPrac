/*
 * @lc app=leetcode.cn id=769 lang=java
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int ans = 0, max = -1;
        for (int i = 0; i < arr.length; ++i) {
            // Slice when max(arr[:i+1]) == i. Without slicing here,
            // there will be an element greater than i in arr[:i+1]
            // and an element less than i in arr[i+1:], which will
            // NOT satisfy the required pattern of a sorted subarray 
            // (e.g. [0, 1, ..., i] or [i + 1, i + 2, ..., n - 1]).
            max = Math.max(max, arr[i]);
            if (max == i) {
                ++ans;
            }
        }
        return ans;
    }
}
// @lc code=end

