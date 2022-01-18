/*
 * @lc app=leetcode.cn id=453 lang=java
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
    public int minMoves(int[] nums) {
        // Let k be the answer and x be the final number in array. 
        // Then: 
        //      k * (n - 1) = x * n - sum(nums).
        // After k operations, the mininum in original array will 
        // become the final number x.
        // Therefore: 
        //      k * (n - 1) + sum(nums) = (min(nums) + k) * n
        //      k = sum(nums) - min(nums) * n
        long sum = 0, min = Long.MAX_VALUE;
        for (int num : nums) {
            min = Math.min(min, num);
            sum += num;
        }
        return (int) (sum - min * nums.length);
        
        // To avoid potential overflow in sum(nums):
        //      k = sum(num - min(nums) for num in nums)
        // int min = Integer.MAX_VALUE; 
        // for (int num : nums) {
        //     min = Math.min(min, num);
        // }
        // int ans = 0;
        // for (int num : nums) {
        //     ans += (num - min);
        // }
        // return ans;
    }
}
// @lc code=end

