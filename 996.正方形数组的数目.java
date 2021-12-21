import java.util.*;
/*
 * @lc app=leetcode.cn id=996 lang=java
 *
 * [996] 正方形数组的数目
 */

// @lc code=start
class Solution {
    int ans;

    // T: O(n!)
    // S: O(n)
    public int numSquarefulPerms(int[] nums) {
        ans = 0;
        Arrays.sort(nums);
        // nums.length <= 12, use a 32-bit int to store seen number
        // Start with 111...1 and finish with 000...0
        int mask = (1 << nums.length) - 1;
        backtrack(nums, new ArrayList<>(), mask);
        return ans;
    }

    private void backtrack(int[] nums, List<Integer> path, int mask) {
        if (path.size() == nums.length) {
            ++ans;
            return;
        }
        for (int i = 0; i < nums.length; ++i) {
            if (((mask >> i) & 1) == 0)  continue;
            if (i > 0 && nums[i] == nums[i - 1] && ((mask >> (i - 1)) & 1) == 1)  continue; // skip duplicates
            if (path.size() == 0 || (path.size() > 0 && isPerfectSq(nums[i] + path.get(path.size() - 1)))) {
                path.add(nums[i]);
                backtrack(nums, path, mask & ~(1 << i));
                path.remove(path.size() - 1);
            }
        }
    }

    private boolean isPerfectSq(int n) {
        int sqrt = (int) Math.sqrt(n);
        return sqrt * sqrt == n;
    }
}
// @lc code=end

