/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */
import java.util.HashMap;

// @lc code=start
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int diff = target - nums[i];
            if (map.containsKey(diff)) {
                return new int[]{map.get(diff), i};
            }
            map.put(nums[i], i);
        }
        return new int[0];
    }
}
// @lc code=end

