/*
 * @lc app=leetcode id=252 lang=golang
 *
 * [252] Meeting Rooms
 */
import "sort"

// @lc code=start
// T: O(n * log(n))
// S: O(log(n)) for sorting
func canAttendMeetings(intervals [][]int) bool {
	// sort by interval start ascending (no need to consider interval end here)
	sort.Slice(intervals, func(i, j int) bool {
		// if intervals[i][0] == intervals[j][0] {
		// 	return intervals[i][1] < intervals[j][1]
		// }
		return intervals[i][0] < intervals[j][1]
	})

	// check if adjacent intervals overlap
	for i := 0; i < len(intervals)-1; i++ {
		if intervals[i+1][0] < intervals[i][1] {
			return false
		}
	}
	return true
}

// @lc code=end

