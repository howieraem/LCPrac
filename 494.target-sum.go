/*
 * @lc app=leetcode id=494 lang=golang
 *
 * [494] Target Sum
 */

// @lc code=start
// A variant of Q416
// T: O(n * (sum(nums) + target))
// S: O(sum(nums) + target)
func findTargetSumWays(nums []int, target int) int {
	/*
		Convert to a knapsack problem (without replacement):
		Suppose knapsack 1's capacity v1 is the sum of numbers that'll be positive in the expression,
		and knapsack 2's capacity v2 is the sum of numbers that'll be negative in the expression.
		Then: v1 + v2 = sum(nums) and v1 - v2 = target; v1 = (sum(nums) + target) // 2.
		The problem becomes how to find the number of ways to fill knapsack 1.
	*/

	sum := 0
	for _, x := range nums {
		sum += x
	}

	if (target > 0 && sum < target) || (target < 0 && sum < -target) {
		// sum(nums) < abs(target), infeasible
		return 0
	}

	sum += target
	if (sum & 1) == 1 {
		// Not divisible by 2, infeasible
		return 0
	}

	v := sum >> 1
	dp := make([]int, v+1)
	dp[0] = 1 // base case, ensures dp[num] = 1 for num in nums

	for _, x := range nums {
		// Reason for iterating backwards: https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation/431026
		for i := v; i >= x; i-- {
			dp[i] += dp[i-x]
		}
	}
	return dp[v]
}

// @lc code=end

