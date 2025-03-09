class Solution {
    // Two pointers
    // T: O(n)
    // S: O(1) if input array can be modified in-place
    public int[] applyOperations(int[] nums) {
        /*
        // Two-pass solution
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }

        int j = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        while (j < nums.length) {
            nums[j++] = 0;
        }
        return nums;
        */

        // One-pass
        int j = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i < nums.length - 1 && nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
            if (j <= i) {
                nums[i] = 0;
            }
        }
        return nums;
    }
}