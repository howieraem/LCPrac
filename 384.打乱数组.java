/*
 * @lc app=leetcode.cn id=384 lang=java
 *
 * [384] 打乱数组
 */
import java.util.Random;

// @lc code=start
class Solution {
    private int[] arr;
    private int[] original;
    private Random rand = new Random();

    public Solution(int[] nums) {
        original = nums;
        arr = original.clone();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        arr = original.clone();
        return original;
    }

    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        for (int i = 0; i < arr.length; ++i) {
            swap(i, randInRange(i, arr.length));
        }
        return arr;
    }


    private int randInRange(int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private void swap(int i, int j) {
        if (i != j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
// @lc code=end

