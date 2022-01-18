/*
 * @lc app=leetcode.cn id=410 lang=java
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
    public int splitArray(int[] nums, int m) {
        int low = getMax(nums), high = getSum(nums);
        while (low < high) {    // break condition: low == high
            int mid = low + (high - low) / 2;
            int n = split(nums, mid);
            if (n <= m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    /**
     * Helper function to caculate the number of split arrays 
     * given the maximum allowed sum of each array.
     */
    private int split(int[] nums, int max) {
        int count = 1, sum = 0;
        for (int num : nums) {
            if (sum + num > max) {
                ++count;
                sum = num;
            } else {
                sum += num;
            }
        }
        return count;
    }

    private int getMax(int[] nums) {
        int max = 0;
        for (int num : nums) {
            max = Math.max(num, max);
        }
        return max;
    }

    private int getSum(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }
}
// @lc code=end

