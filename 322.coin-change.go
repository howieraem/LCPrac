/*
 * @lc app=leetcode id=322 lang=golang
 *
 * [322] Coin Change
 */
package lc

import "math"

// @lc code=start
// T: O(len(coins) * amount)
// S: O(amount)
func coinChange(coins []int, amount int) int {
	var dp = make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		dp[i] = math.MaxInt

		for _, coin := range coins {
			if i >= coin && dp[i-coin] != math.MaxInt && dp[i] > dp[i-coin]+1 {
				dp[i] = dp[i-coin] + 1
			}
		}
	}

	if dp[amount] == math.MaxInt {
		return -1
	}
	return dp[amount]
}

// @lc code=end
