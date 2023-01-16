/*
 * @lc app=leetcode id=202 lang=golang
 *
 * [202] Happy Number
 */

// @lc code=start
func nextNum(n int) int {
	sum := 0
	for n > 0 {
		digit := n % 10
		sum += digit * digit
		n /= 10
	}
	return sum
}

// Similar to finding a cycle in a linked data structure
// T: O(log(n) * max_iter)
// S: O(1)
func isHappy(n int) bool {
	slow := nextNum(n)
	fast := nextNum(nextNum(n))

	for slow != fast {
		slow = nextNum(slow)
		fast = nextNum(nextNum(fast))
	}

	return slow == 1
}

// @lc code=end

