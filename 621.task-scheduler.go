/*
 * @lc app=leetcode id=621 lang=golang
 *
 * [621] Task Scheduler
 */

// @lc code=start
// Greedy strategy: run the type of tasks with max. count first, separated by other types of tasks
// T: O(n)
// S: O(s), s := the number of task types
func leastInterval(tasks []byte, n int) int {
    var cnts [26]int
	maxCnt := 0
	numOfTasksWithMaxCnt := 0
	for _, task := range tasks {
		ci := task - 'A'
		cnts[ci]++
		if cnts[ci] == maxCnt {
			numOfTasksWithMaxCnt++
		} else if cnts[ci] > maxCnt {
			maxCnt = cnts[ci]
			numOfTasksWithMaxCnt = 1
		}
	}

	// Example: if A has the max. count and n = 2, then we should schedule like [A, x, x, A, x, x, A, ...],
	// where x is any other types of tasks. Consider the subarray [x, x] which has length n. If there exist 
	// other types of tasks also having the max. count, some of the subarray slots must be used by these 
	// most frequent tasks. Using the number of tasks with smaller counts and the number of slots for 
	// these less frequent tasks to get the answer, we can get the number of idle slots, and then the answer.
	numOfSlotsForLessFreqTasks := (maxCnt - 1) * (n - (numOfTasksWithMaxCnt - 1))  // minus 1 since one of the most frequent tasks like A is used
	numOfLessFreqTasks := len(tasks) - maxCnt * numOfTasksWithMaxCnt
	numOfIdleSlots := numOfSlotsForLessFreqTasks - numOfLessFreqTasks
	if numOfIdleSlots < 0 {
		// IMPORTANT: If numOfIdleSlots becomes negative here, it means there are more 
		// less-frequent tasks to separate the same type of most-frequent tasks, so 
		// there won't be any idle slots
		// numOfIdleSlots = 0
		return len(tasks)
	}
	return len(tasks) + numOfIdleSlots
}
// @lc code=end

