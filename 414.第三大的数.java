/*
 * @lc app=leetcode.cn id=414 lang=java
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
    public int thirdMax(int[] nums) {
        long max1 = Long.MIN_VALUE, max2 = Long.MIN_VALUE, max3 = Long.MIN_VALUE;
        // for (int num : nums) {
        //     max1 = Math.max(num, max1);
        // }

        // for (int num : nums) {
        //     if (num < max1) {
        //         max2 = Math.max(max2, num);
        //     }
        // }

        // for (int num : nums) {
        //     if (num < max2) {
        //         max3 = Math.max(max3, num);
        //     }
        // }

        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num != max1 && num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num != max1 && num != max2 && num > max3) {
                max3 = num;
            }
        }
        return (int) (max3 == Long.MIN_VALUE ? max1 : max3);
    }
}
// @lc code=end

