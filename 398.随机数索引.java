/*
 * @lc app=leetcode.cn id=398 lang=java
 *
 * [398] 随机数索引
 */
import java.util.Random;

// @lc code=start
// S: O(n), or O(1) if storing pointer to the array
class Solution {
    private int[] nums;
    private static final Random RAND = new Random();

    // T: O(n), or O(1) if storing pointer to the array
    public Solution(int[] nums) {
        this.nums = nums;
    }
    
    // T: O(n)
    public int pick(int target) {
        int cur_cnt = 0, idx = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == target) {
                ++cur_cnt;
                if (RAND.nextInt(cur_cnt) == 0) {
                    // Random().nextInt(n) returns an integer in
                    // interval [0, n) with equal probability
                    // The probability of 0 being selected is 1 / cnt.
                    // The probability of a non-zero number being selected is 1 - 1 / cnt.
                    // Example: {1, 2, 3, 3, 3}, target = 3
                    // P(i = 2) = 1 * (1 / 2) * (2 / 3) = 1 / 3
                    // P(i = 3) = (1 / 2) * (2 / 3) = 1 / 3
                    // P(i = 4) = 1 / 3
                    // P(i = x) = P(x selected) * P(x not replaced if previously selected)
                    idx = i;
                } // for other numbers between [0,]
            }
        }
        return idx;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
// @lc code=end

