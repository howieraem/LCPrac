/*
 * @lc app=leetcode id=55 lang=golang
 *
 * [55] Jump Game
 */

// @lc code=start
// T: O(n)
// S: O(1)
func canJump(nums []int) bool {
	end := len(nums) - 1
	reachable := 0

	// iterate i til n-2 because nums[n-1] has no effect
	for i := 0; i < end; i++ {
		// greedy: always jump as many steps as possible
		curReachable := i + nums[i]
		if reachable < curReachable {
			reachable = curReachable
			if reachable >= end {
				return true
			}
		}

		if reachable <= i {
			// IMPORTANT: reachable == i means the jump will always end at i,
			// but i < end, so impossible to reach the end. This happens when
			// nums[i] <= 0.
			return false
		}
	}

	// don't forget the last check
	return reachable >= end
}

// @lc code=end

