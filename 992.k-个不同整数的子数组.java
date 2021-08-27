import java.util.*;
/*
 * @lc app=leetcode.cn id=992 lang=java
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return getMostDistinct(nums, k) - getMostDistinct(nums, k - 1);
    }

    // Returns the number of subarrays with at most k different integers
    private static int getMostDistinct(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        int n = nums.length, ans = 0, cnt = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            freq.put(nums[r], freq.getOrDefault(nums[r], 0) + 1);
            if (freq.get(nums[r]) == 1) {
                // A new integer value appeared in the window
                ++cnt;
            }
            while (cnt > k) {
                freq.put(nums[l], freq.get(nums[l]) - 1);
                if (freq.get(nums[l]) == 0) {
                    // An integer has disappeared while shifting the window's 
                    // left boundary
                    --cnt;
                }
                ++l;
            }
            // There are (r - l + 1) new subarrays in this iteration
            ans += r - l + 1;
        }
        return ans;
    }
}
// @lc code=end

