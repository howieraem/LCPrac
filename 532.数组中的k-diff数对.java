/*
 * @lc app=leetcode.cn id=532 lang=java
 *
 * [532] 数组中的K-diff数对
 */
import java.util.Set;
import java.util.HashSet;

// @lc code=start
class Solution {
    public int findPairs(int[] nums, int k) {
        Set<Integer> visited = new HashSet<>();
        Set<Integer> diff = new HashSet<>();  // stores the smaller number of a k-diff pair and avoids repetition
        for (int num : nums) {
            if (visited.contains(num - k))
                diff.add(num - k);
            if (visited.contains(num + k))
                diff.add(num);
            visited.add(num);
        }
        return diff.size();
    }
}
// @lc code=end

