import java.util.*;
/*
 * @lc app=leetcode.cn id=47 lang=java
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();

        // nums.length <= 8, use a 32-bit int to store seen number
        int mask = (1 << nums.length) - 1;   // pow(2, nums.length-1) = 0b11...1
        // boolean[] seen = new boolean[nums.length];
        backtrack(nums, new ArrayList<>(), res, mask);
        // backtrack(nums, new ArrayList<>(), res, seen);
        return res;
    }

    private static void backtrack(int[] nums, List<Integer> path, List<List<Integer>> res, int mask) {
    // private static void backtrack(int[] nums, List<Integer> path, List<List<Integer>> res, boolean[] seen) {
        if (mask == 0) {
        // if (path.size() == nums.length) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < nums.length; ++i) {
            if (((mask >> i) & 1) == 0)  continue;
            // if (seen[i])  continue;
            if (i > 0 && nums[i] == nums[i - 1] && ((mask >> (i - 1)) & 1) == 1)  continue;
            // if (i > 0 && nums[i] == nums[i - 1] && !seen[i - 1])  continue;
            path.add(nums[i]);
            // mask &= ~(1 << i);
            // seen[i] = true;
            backtrack(nums, path, res, mask & ~(1 << i));
            // backtrack(nums, path, res, seen);
            path.remove(path.size() - 1);
            // mask |= (1 << i);
            // seen[i] = false;
        }
    }
}
// @lc code=end

