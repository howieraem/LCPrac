/*
 * @lc app=leetcode id=680 lang=golang
 *
 * [680] Valid Palindrome II
 */
package lc

// @lc code=start
// Two pointers
// T: O(n)
// S: O(1)
func validPalindrome(s string) bool {
	l := 0
	r := len(s) - 1
	for l < r {
		if s[l] != s[r] {
			// We allow one mismatch, so skip either left char or right char,
			// and continue checking
			return validPalindromeHelper(s, l+1, r) || validPalindromeHelper(s, l, r-1)
		}
		l++
		r--
	}
	return true
}

func validPalindromeHelper(s string, l int, r int) bool {
	for l < r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}
	return true
}

// @lc code=end
