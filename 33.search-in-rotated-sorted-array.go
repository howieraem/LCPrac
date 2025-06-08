/*
 * @lc app=leetcode id=33 lang=golang
 *
 * [33] Search in Rotated Sorted Array
 */
package lc

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
		} else if nums[m] < nums[l] {
			if nums[m] < target && target <= nums[r] {
				l = m + 1
			} else {
				r = m - 1
			}
		} else {
			if nums[l] <= target && target < nums[m] {
				r = m - 1
			} else {
				l = m + 1
			}
		}
	}
	return -1
}

// @lc code=end
