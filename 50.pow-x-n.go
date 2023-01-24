/*
 * @lc app=leetcode id=50 lang=golang
 *
 * [50] Pow(x, n)
 */

// @lc code=start
func expBySquaring(x float64, n int) float64 {
	ans := 1.
	for n != 0 {
		if (n & 1) == 1 {
			ans *= x
		}
		x *= x
		n >>= 1
	}
	return ans
}

// T: O(log(n))
// S: O(1)
func myPow(x float64, n int) float64 {
	if n >= 0 {
		return expBySquaring(x, n)
	}
	return 1.0 / expBySquaring(x, -n)
}

// @lc code=end

