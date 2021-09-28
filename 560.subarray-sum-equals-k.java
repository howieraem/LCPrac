import java.util.*;

/*
 * @lc app=leetcode id=560 lang=java
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> prefixSumFreq = new HashMap<>();
        prefixSumFreq.put(0, 1);

        int curSum = 0, ans = 0;
        for (int num : nums) {
            curSum += num;
            int diff = curSum - k;
            if (prefixSumFreq.containsKey(diff)) {
                ans += prefixSumFreq.get(diff);
            }
            prefixSumFreq.put(curSum, prefixSumFreq.getOrDefault(curSum, 0) + 1);
        }
        return ans;
    }
}
// @lc code=end

