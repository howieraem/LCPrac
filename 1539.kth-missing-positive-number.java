/*
 * @lc app=leetcode id=1539 lang=java
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
    // Binary search
    // T: O(log(n))
    // S: O(1)
    public int findKthPositive(int[] arr, int k) {
        int l = 0;
        int r = arr.length;

        while (l < r) {
            int m = l + ((r - l) >> 1);

            // The correct index of m-th number without any missing positive numbers is m + 1 
            // (1-indexed as zero doesn't count).
            // The number of missing positive numbers under arr[m] is arr[m] - (m + 1). 
            if (arr[m] - (m + 1) < k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        // while loop exit condition: l == r, meaning that 
        // the number of missing positive numbers explored is k.
        return l + k;
    }
}
// @lc code=end

