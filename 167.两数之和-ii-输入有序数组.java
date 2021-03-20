/*
 * @lc app=leetcode.cn id=167 lang=java
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0, right = numbers.length - 1;
        while (left < right) {
            int tmp = numbers[left] + numbers[right];
            if (tmp == target) {
                return new int[] {left+1, right+1};
            } else if (tmp > target) {
                --right;
            } else {
                ++left;
            }
        }
        return new int[0];
    }
}
// @lc code=end

