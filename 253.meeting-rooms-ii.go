/*
 * @lc app=leetcode id=253 lang=golang
 *
 * [253] Meeting Rooms II
 */
import "sort"

// @lc code=start
// Sort interval starts and ends separately, and then check overlaps
// T: O(n * log(n))
// S: O(n) for copying
func minMeetingRooms(intervals [][]int) int {
	n := len(intervals)

	starts := make([]int, n)
	ends := make([]int, n)
	for i := range intervals {
		starts[i] = intervals[i][0]
		ends[i] = intervals[i][1]
	}

	sort.Ints(starts)
	sort.Ints(ends)

	curEndIdx := 0
	ans := 0
	for i := 0; i < n; i++ {
		if starts[i] < ends[curEndIdx] {
			// overlap, need a new room
			ans++
		} else {
			// no overlap, reuse an existing room
			curEndIdx++
		}
	}
	return ans
}

// @lc code=end

