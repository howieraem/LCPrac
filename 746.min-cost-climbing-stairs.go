/*
 * @lc app=leetcode id=746 lang=golang
 *
 * [746] Min Cost Climbing Stairs
 */
package lc

// @lc code=start
// T: O(n)
// S: O(1)
func minCostClimbingStairs(cost []int) int {
	// base cases
	dpI2 := cost[0] // dp[i-2], the minimum cost before climbing 2 steps
	dpI1 := cost[1] // dp[i-1], the minimum cost before climbing 1 step

	for i := 2; i < len(cost); i++ {
		var dpI int // dp[i]
		if dpI2 < dpI1 {
			// Cheaper to climb 2 steps to reach the current position
			dpI = dpI2 + cost[i]
		} else {
			// Cheaper to climb 1 step to reach the current position
			dpI = dpI1 + cost[i]
		}

		// discard older state values
		dpI2 = dpI1
		dpI1 = dpI
	}

	// IMPORTANT: the destination is at index n = len(cost).
	// To reach that position, either cost[n - 2] or cost[n - 1] must be involved.
	if dpI2 < dpI1 {
		// Cheaper to climb from cost[n - 2]
		return dpI2
	}
	// Cheaper to climb from cost[n - 1]
	return dpI1
}

// @lc code=end
