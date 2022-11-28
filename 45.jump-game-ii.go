/*
 * @lc app=leetcode id=45 lang=golang
 *
 * [45] Jump Game II
 */

// @lc code=start
// T: O(n)
// S: O(1)
func jump(nums []int) int {
	end := len(nums) - 1
	ans := 0
	reachable := 0
	pos := 0

	for i := 0; i < end; i++ {
		newReachable := i + nums[i]
		if reachable < newReachable {
			reachable = newReachable
		}

		// Jump to the furthest pos reachable, greedy
		if pos == i {
			if reachable == i {
				// can't jump forward, the end isn't reachable
				return -1
			}

			pos = reachable
			ans++
		}
	}

	return ans
}

// @lc code=end

