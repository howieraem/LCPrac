/*
 * @lc app=leetcode id=1143 lang=golang
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
// T: O(m * n)
// S: O(min(m, n))
func longestCommonSubsequence(text1 string, text2 string) int {
	if len(text1) > len(text2) {
		text2, text1 = text1, text2
	}

	m := len(text1)
	n := len(text2)

	/*
		// Naive 2D DP
		dp := make([][]int, m+1)
		for i := 0; i <= m; i++ {
			dp[i] = make([]int, n+1)
		}

		for i := 1; i <= m; i++ {
			for j := 1; j <= n; j++ {
				if text1[i-1] == text2[j-1] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else if dp[i-1][j] > dp[i][j-1] {
					dp[i][j] = dp[i-1][j]
				} else {
					dp[i][j] = dp[i][j-1]
				}
			}
		}
		return dp[m][n]
	*/

	// Space-optimized 1D DP
	dp := make([]int, n+1)

	for i := 1; i <= m; i++ {
		dpI1J1 := dp[0]
		for j := 1; j <= n; j++ {
			dpI1 := dp[j]

			if text1[i-1] == text2[j-1] {
				dp[j] = dpI1J1 + 1
			} else if dp[j-1] > dpI1 {
				dp[j] = dp[j-1]
			} else {
				dp[j] = dpI1
			}

			dpI1J1 = dpI1
		}
	}
	return dp[n]
}

// @lc code=end

