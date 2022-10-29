/*
 * @lc app=leetcode id=5 lang=golang
 *
 * [5] Longest Palindromic Substring
 */
package lc

// @lc code=start
// Two pointers, extend the palindrome with s[l] and s[r] as center as much as possible
func findPalindrome(s string, l int, r int) (int, int) {
	for l >= 0 && r < len(s) && s[l] == s[r] {
		l--
		r++
	}

	// Undo last iteration changes
	l++
	r--

	return r - l + 1, l
}

// T: O(n ^ 2)
// S: O(n) substring copy
func longestPalindrome(s string) string {
	n := len(s)
	if n == 0 {
		return s
	}

	begin := 0
	length := 1

	for i := range s {
		// Try forming a long palindrome with odd length
		oddPalindromeLen, oddPalindromeBegin := findPalindrome(s, i, i)
		if length < oddPalindromeLen {
			begin = oddPalindromeBegin
			length = oddPalindromeLen
		}

		// Try forming a long palindrome with even length
		evenPalindromeLen, evenPalindromeBegin := findPalindrome(s, i, i+1)
		if length < evenPalindromeLen {
			begin = evenPalindromeBegin
			length = evenPalindromeLen
		}
	}

	return s[begin : begin+length]
}

// @lc code=end
