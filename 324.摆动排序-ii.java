import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=324 lang=java
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
    public void wiggleSort(int[] nums) {
        int[] clone = nums.clone();
        Arrays.sort(clone);
        int n = nums.length;
        for (int i = 1; i < nums.length; i += 2) {
            nums[i] = clone[--n];   // copy items with odd indices
        }
        for (int i = 0; i < nums.length; i += 2) {
            nums[i] = clone[--n];   // copy items with even indices
        }
    }
}
// @lc code=end

