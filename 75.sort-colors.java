/*
 * @lc app=leetcode id=75 lang=java
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(1)
    public void sortColors(int[] nums) {
        int pRed = 0;
        int pWhite = 0;
        int pBlue = nums.length - 1;

        // Similar to quick sort
        while (pWhite <= pBlue) {
            if (nums[pWhite] == 0) {
                swap(nums, pWhite, pRed);
                pWhite++;
                pRed++;
            } else if (nums[pWhite] == 1) {
                pWhite++;
            } else {
                // Why not incr pWhite:
                // We assume all the elements to the left of pWhite to be color-classified and 
                // all the elements to the right (and including) pWhite to be color-unclassified.
                swap(nums, pWhite, pBlue);
                pBlue--;
            }
        }
    }

    private static void swap(int[] nums, int i, int j) {
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }
}
// @lc code=end

