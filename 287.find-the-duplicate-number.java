/*
 * @lc app=leetcode id=287 lang=java
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
    // Solution 1: Fast slow pointers + Cyclic sort?
    // Although there exist other solutions with space complexity O(1), this solution avoids modifying the input nums
    // T: O(n) two passes
    // S: O(1)
    public int findDuplicate(int[] nums) {
        // Equivalent to finding a cycle in linked list
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;  // found a cycle
            }
        }

        // Now find the cycle's entrance
        fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            if (slow == fast) {
                return slow;
            }
        }
    }

    // Solution 2: Mark visited + simplified cyclic sort? 
    // T: O(n) one pass, but nums modified
    // S: O(1)
    public static int findDuplicate_mark(int[] nums) {
        final int n = nums.length;
        for (int num : nums) {
            int idx = Math.abs(num);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }

        return n;
    }
}
// @lc code=end

