import java.util.*;
/*
 * @lc app=leetcode.cn id=448 lang=java
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        // O(1) space
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            // Try mapping unordered array to ordered array [1, ..., n]
            // by getting each element's index in the 
            // sorted array which is its value minus 1.
            //
            // Mark seen numbers negative,
            // so need to use abs() for
            // those already seen.
            int idx = Math.abs(nums[i]) - 1;
            if (nums[idx] > 0)  nums[idx] *= -1;
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            // Reverse mapping: if nums[i] is unseen, 
            // then i + 1 is missing
            if (nums[i] > 0)  res.add(i + 1);
        }
        return res;
    }
}
// @lc code=end

