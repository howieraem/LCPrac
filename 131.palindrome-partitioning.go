/*
 * @lc app=leetcode id=131 lang=golang
 *
 * [131] Palindrome Partitioning
 */
package lc

// @lc code=start
func backtrack(s string, begin int, isPalindrome [][]bool, parts *[]string, res *[][]string) {
	if begin == len(s) {
		*res = append(*res, append([]string{}, *parts...))
		return
	}

	for i := begin; i < len(s); i++ {
		if isPalindrome[begin][i] {
			*parts = append(*parts, s[begin:i+1])
			backtrack(s, i+1, isPalindrome, parts, res)
			*parts = (*parts)[:len(*parts)-1]
		}
	}
}

// T: O(n * 2 ^ n)
// S: O(n ^ 2)
func partition(s string) [][]string {
	n := len(s)

	// dp[i][j] means whether s[i:j+1] is a palindrome.
	dp := make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
	}
	for r := 0; r < n; r++ {
		for l := 0; l <= r; l++ {
			if s[l] == s[r] && (r-l <= 2 || dp[l+1][r-1]) {
				dp[l][r] = true
			}
		}
	}

	var res [][]string
	var parts []string
	backtrack(s, 0, dp, &parts, &res)
	return res
}

// @lc code=end
