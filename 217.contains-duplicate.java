/*
 * @lc app=leetcode id=217 lang=java
 *
 * [217] Contains Duplicate
 */
import java.util.*;

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(n)
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int x : nums) {
            if (seen.contains(x)) return true;
            seen.add(x);
        }
        return false;
    }
}
// @lc code=end

