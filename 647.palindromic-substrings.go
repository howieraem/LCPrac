/*
 * @lc app=leetcode id=647 lang=golang
 *
 * [647] Palindromic Substrings
 */
package lc

// @lc code=start
// Two pointers, extend the palindrome with s[l] and s[r] as center as much as possible
func countPalindrome(s string, l int, r int) int {
	cnt := 0

	for l >= 0 && r < len(s) && s[l] == s[r] {
		l--
		r++
		cnt++
	}

	return cnt
}

// T: O(n ^ 2)
// S: O(1)
func countSubstrings(s string) int {
	ans := 0

	for i := range s {
		// Extending from each char, try forming palindromes of odd lengths and even lengths
		ans += countPalindrome(s, i, i) + countPalindrome(s, i, i+1)
	}

	return ans
}

// @lc code=end

