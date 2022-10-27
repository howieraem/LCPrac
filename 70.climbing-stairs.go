/*
 * @lc app=leetcode id=70 lang=golang
 *
 * [70] Climbing Stairs
 */
package lc

// @lc code=start
// T: O(n)
// S: O(1)
func climbStairs(n int) int {
	// base cases
	dpI2 := 1 // dp[i-2], the number of ways before jumping 2 steps
	dpI1 := 1 // dp[i-1], the number of ways before jumping 1 step

	dpI := 1 // dp[i], the total number of ways, initialized to 1 in case n = 1

	for i := 2; i <= n; i++ {
		dpI = dpI2 + dpI1

		// discard older state values
		dpI2 = dpI1
		dpI1 = dpI
	}
	return dpI
}

// @lc code=end
