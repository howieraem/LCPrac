/*
 * @lc app=leetcode id=128 lang=java
 *
 * [128] Longest Consecutive Sequence
 */
import java.util.*;

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(n)
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int x : nums) {
            set.add(x);
        }

        int ans = 0;
        for (int x : set) {
            // IMPORTANT: this check will make the search only start from the smallest element of the sequence,
            // reducing time complexity from O(n ^ 2) to O(n)
            if (!set.contains(x - 1)) {
                int y = x + 1;
                while (set.contains(y)) {
                    ++y;
                }
                ans = Math.max(ans, y - x);
            }
        }

        return ans;
    }
}
// @lc code=end

