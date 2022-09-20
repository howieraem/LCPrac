/*
 * @lc app=leetcode id=704 lang=golang
 *
 * [704] Binary Search
 */

// @lc code=start
// T: O(log(n))
// S: O(1)
func search(nums []int, target int) int {
    l := 0
	r := len(nums) - 1
	for l <= r {
		m := l + ((r - l) >> 1)
		if nums[m] == target {
			return m
		} else if nums[m] > target {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return -1
}
// @lc code=end

