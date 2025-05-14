/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */
package lc

// @lc code=start
// Hash Map
// T: O(n)
// S: O(n)
func twoSum(nums []int, target int) []int {
	mp := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if j, ok := mp[target-nums[i]]; ok {
			return []int{j, i}
		} else {
			mp[nums[i]] = i
		}
	}
	return []int{}
}

// @lc code=end
