/*
 * @lc app=leetcode id=198 lang=golang
 *
 * [198] House Robber
 */
package lc

// @lc code=start
// T: O(n)
// S: O(1)
func rob(nums []int) int {
	dpI2 := 0 // dp[i-2]
	dpI1 := 0 // dp[i-1]
	dpI := 0  // dp[i]

	for i := range nums {
		// Rob either previous, or current and previous of previous
		// dp[i] = max(dp[i-1], dp[i-2]+nums[i])
		if dpI2+nums[i] > dpI1 {
			dpI = dpI2 + nums[i]
		} else {
			dpI = dpI1
		}

		dpI2 = dpI1
		dpI1 = dpI
	}

	return dpI
}

// @lc code=end
