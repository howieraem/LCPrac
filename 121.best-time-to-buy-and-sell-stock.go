/*
 * @lc app=leetcode id=121 lang=golang
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
// Sliding window approach
// T: O(n)
// S: O(1)
func maxProfit(prices []int) int {
    l := 0
	r := 1
	ans := 0
	for r < len(prices) {
		curProfit := prices[r] - prices[l]  // try selling
		if curProfit <= 0 {
			// Buy time and sell time not appropriate, so shift the left boundary  
			// of the window, equivalent to buying at a later time
			l = r
		} else if curProfit > ans {
			// Buy time and sell time yields a positive profit, update the answer
			ans = curProfit
		}
		r++
	}
	return ans
}
// @lc code=end

