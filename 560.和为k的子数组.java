import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=560 lang=java
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
    public int subarraySum(int[] nums, int k) {
        // Based on the idea in Q1, use a hash map to store 
        // the number of appearances of prefix sums
        int n = nums.length;
        HashMap<Integer, Integer> prefixSums = new HashMap<>();
        prefixSums.put(0, 1);
        
        int ans = 0, sum_0_to_i = 0;
        for (int i = 0; i < n; ++i) {
            sum_0_to_i += nums[i];
            int sum_0_to_j = sum_0_to_i - k;
            if (prefixSums.containsKey(sum_0_to_j)) {
                ans += prefixSums.get(sum_0_to_j);
            }
            prefixSums.put(sum_0_to_i, 
                           prefixSums.getOrDefault(sum_0_to_i, 0) + 1);
        }
        return ans;
    }
}
// @lc code=end

