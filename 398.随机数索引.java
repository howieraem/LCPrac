/*
 * @lc app=leetcode.cn id=398 lang=java
 *
 * [398] 随机数索引
 */
import java.util.Random;

// @lc code=start
class Solution {
    private int[] nums;
    private static final Random RAND = new Random();

    public Solution(int[] nums) {
        this.nums = nums;
    }
    
    public int pick(int target) {
        int cnt = 0, idx = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == target) {
                ++cnt;
                if (RAND.nextInt(cnt) == 0) {
                    // Random().nextInt(n) returns an integer in
                    // interval [0, n) with equal probability
                    idx = i;
                }
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

