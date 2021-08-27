import java.util.*;
/*
 * @lc app=leetcode.cn id=719 lang=java
 *
 * [719] 找出第 k 小的距离对
 */

// @lc code=start
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);

        // Binary search (lower bound)
        int l = 0, r = nums[nums.length - 1] - nums[0];
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (countGreater(nums, m) >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    // Count the number of pairwise distance greater than dist
    // via sliding window
    private static int countGreater(int[] nums, int dist) {
        int cnt = 0, l = 0, r = 0;
        while (r < nums.length) {
            while (l < r && nums[r] - nums[l] > dist) {
                ++l;
            } 
            cnt += r - l;
            ++r;
        }
        return cnt;
    }
}
// @lc code=end

