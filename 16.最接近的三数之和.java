import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=16 lang=java
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
    // T: O(n ^ 2)
    // S: O(1)
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])  continue;  // skip duplicates
            int l = i + 1, r = nums.length - 1;
            while (l < r) {
                int sum3 = nums[i] + nums[l] + nums[r];
                if (Math.abs(target - sum3) < Math.abs(target - ans)) {
                    ans = sum3;
                }
                if (sum3 > target) {
                    --r;
                } else if (sum3 < target) {
                    ++l;
                } else {
                    // No need to skip duplicates of y and z here because
                    // we are only looking for the closest sum
                    return ans;
                }
            }
        }
        return ans;
    }
}
// @lc code=end
