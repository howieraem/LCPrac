/*
 * @lc app=leetcode id=56 lang=golang
 *
 * [56] Merge Intervals
 */
import "sort"

// @lc code=start
// T: O(n * log(n))
// S: O(log(n)) for Pattern-defeating Quicksort implementation; not considering result space usage
func merge(intervals [][]int) [][]int {
	// Sort intervals by start ascending
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	var res [][]int
	curInterval := &intervals[0]

	for i := 1; i < len(intervals); i++ {
		if (*curInterval)[1] < intervals[i][0] {
			// no overlap
			res = append(res, *curInterval)
			curInterval = &intervals[i]
		} else if (*curInterval)[1] < intervals[i][1] {
			// overlap
			(*curInterval)[1] = intervals[i][1]
		}
	}

	// Append the last interval
	res = append(res, *curInterval)

	return res
}

// @lc code=end

