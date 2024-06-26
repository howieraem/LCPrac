/*
 * @lc app=leetcode id=518 lang=golang
 *
 * [518] Coin Change 2
 */

// @lc code=start
// Knapsack problem (with replacements)
// T: O(n * amount)
// S: O(amount)
func change(amount int, coins []int) int {
	dp := make([]int, amount+1)
	dp[0] = 1 // base case, ensures dp[coin] = 1 for coin in coins

	// IMPORTANT:
	// There actually exists a naive 2D DP where we can have coins
	// in the inner loop. However, when we have the space-optimized
	// 1D DP, we must have coins in the outer loop, otherwise we are
	// counting the unique permutations like Q377 (but the question
	// asks for unique combinations). Detailed explanation:
	// https://leetcode.com/problems/coin-change-ii/discuss/176706/Beginner-Mistake:-Why-an-inner-loop-for-coins-doensn't-work-Java-Soln/306232
	for _, coin := range coins {
		for i := coin; i <= amount; i++ {
			dp[i] += dp[i-coin]
		}
	}

	// If we really want coins in the inner loop, we need sorting and special value initializations:
	// https://leetcode.com/problems/combination-sum-iv/discuss/111860/Coin-change-AND-this-problem/512140

	return dp[amount]
}

// @lc code=end

