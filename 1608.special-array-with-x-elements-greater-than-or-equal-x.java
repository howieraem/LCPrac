/*
 * @lc app=leetcode id=1608 lang=java
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution {
    // Hash Map + bucket sort
    // T: O(n)
    // S: O(n)
    public int specialArray(int[] nums) {
        final int n = nums.length;
        int[] freqs = new int[n + 1];
        
        for (int x : nums) {
            ++freqs[x >= n ? n : x];
        }

        int cnt = 0;

        // Reverse iteration, because the target needs to be 
        // greater than or equal to some other numbers in nums
        for (int i = n; i > 0; --i) {
            cnt += freqs[i];
            if (cnt == i) {
                return i;
            }
        }

        return -1;
    }
}
// @lc code=end

