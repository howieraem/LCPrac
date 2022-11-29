/*
 * @lc app=leetcode id=134 lang=golang
 *
 * [134] Gas Station
 */

// @lc code=start
// T: O(n)
// S: O(1)
func canCompleteCircuit(gas []int, cost []int) int {
	curGas := 0
	netGas := 0
	start := 0

	for i := range gas {
		gasGain := gas[i] - cost[i]
		curGas += gasGain
		if curGas < 0 {
			// Greedy: When it's impossible to reach the next station from the current start,
			// any stations between the current start and the current station (incl.) cannot
			// reach the next station. We skip these and start at the next station instead.
			curGas = 0
			start = i + 1
		}
		netGas += gasGain
	}

	// There must be a solution if the total gas is greater than the total cost.
	// No need to go through the stations again to simulate circle.
	if netGas >= 0 {
		return start
	}
	return -1
}

// @lc code=end

