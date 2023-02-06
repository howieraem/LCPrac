/*
 * @lc app=leetcode id=136 lang=golang
 *
 * [136] Single Number
 */

// @lc code=start
// Based on x ^ x = 0 and x ^ 0 = x.
// T: O(n)
// S: O(1)
func singleNumber(nums []int) int {
	mask := nums[0]
	for i := 1; i < len(nums); i++ {
		mask ^= nums[i]
	}
	return mask
}

// @lc code=end

