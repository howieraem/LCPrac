class Solution {
    // Greedy + Bit Manipulation + Sliding window?
    // T: O(n * w), w := 3
    // S: O(1)
    public int minOperations(int[] nums) {
        // Whenever we encounter a zero, flip it as well as the next two numbers.
        // Leave the last two numbers unchanged and see if they are both ones.
        final int n = nums.length;

        int ans = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++ans;
            }
        }

        return (nums[n - 2] == 1 && nums[n - 1] == 1) ? ans : -1;
    }
}