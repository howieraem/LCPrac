/*
 * @lc app=leetcode id=53 lang=golang
 *
 * [53] Maximum Subarray
 */
import "math"

// @lc code=start
// Simple DP
// T: O(n)
// S: O(1)
func maxSubArray(nums []int) int {
	ans := math.MinInt
	curSum := 0

	for _, x := range nums {
		newSum := curSum + x
		if newSum > x {
			// Extend the current subarray
			curSum = newSum
		} else {
			// Better to start a new subarray. This happens when
			// curSum becomes a negative number with a large
			// absolute value.
			curSum = x
		}

		// Need to update answer in every iteration because
		// the subarray can be somewhere in the middle
		if ans < curSum {
			ans = curSum
		}
	}
	return ans
}

// @lc code=end

