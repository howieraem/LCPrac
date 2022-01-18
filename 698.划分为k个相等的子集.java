import java.util.*;
/*
 * @lc app=leetcode.cn id=698 lang=java
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
    private int n;
    private int[] nums;

    public boolean canPartitionKSubsets(int[] nums, int k) {
        n = nums.length;
        int sum = 0;
        for (int i = 0; i < n; ++i)  sum += nums[i];
        if (sum % k != 0)  return false;
        int target = sum / k;
        Arrays.sort(nums);
        if (nums[n - 1] > target)  return false;
        this.nums = nums;
        return dfs(n - 1, target, 0, k, new boolean[n]);
    }

    private boolean dfs(int begin, int target, int cur, int k, boolean[] seen) {
        if (k == 1)  return true;
        if (cur == target) {
            // partition
            return dfs(n - 1, target, 0, k - 1, seen);
        }
        // Reverse the loop will reduce the total iterations
        for (int i = begin; i >= 0; --i) {
            if (seen[i])  continue;
            int next = cur + nums[i];
            if (next > target)  continue;
            seen[i] = true;
            if (dfs(i - 1, target, next, k, seen))  return true;
            seen[i] = false;
            while (i > 0 && nums[i - 1] == nums[i])  --i;
        }
        return false;
    }
}
// @lc code=end

