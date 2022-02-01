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
        int ans = nums[0] + nums[1] + nums[2], minDiff = Math.abs(target - ans);
        for (int i = 0; i < nums.length - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])  continue;  // skip duplicates
            int l = i + 1, r = nums.length - 1;
            while (l < r) {
                int sum3 = nums[i] + nums[l] + nums[r], curDiff = Math.abs(target - sum3);
                if (curDiff < minDiff) {
                    ans = sum3;
                    minDiff = curDiff;
                }
                if (sum3 > target) {
                    --r;
                } else if (sum3 < target) {
                    ++l;
                } else {
                    return ans;
                    // Return early as sum3 == target, can't be closer.
                    // We don't care about what the actual triplets are
                    // and their uniqueness, so there is no need to skip
                    // duplicates of nums[l] or nums[r] (unlike Q15)
                }
            }
        }
        return ans;
    }
}
// @lc code=end
