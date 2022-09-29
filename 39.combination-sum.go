/*
 * @lc app=leetcode id=39 lang=golang
 *
 * [39] Combination Sum
 */
package lc

import "sort"

// @lc code=start
func backtrack(candidates []int, path *[]int, remain int, res *[][]int) {
	if remain == 0 {
		combo := make([]int, len(*path))
		copy(combo, *path)
		*res = append(*res, combo)
	}
	// The same number may be chosen from candidates an unlimited number of times,
	// so iterate all candidates (with some pruning)
	for _, num := range candidates {
		if num > remain {
			// IMPORTANT prune: stop if exceeding target
			break
		}
		if len(*path) != 0 && num < (*path)[len(*path)-1] {
			// IMPORTANT prune: don't reuse smaller numbers
			continue
		}
		*path = append(*path, num)
		backtrack(candidates, path, remain-num, res)
		*path = (*path)[:len(*path)-1]
	}
}

// T: O(len(candidates) ^ target) worst case
// S: O(len(candidates) * target) ?
func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates) // sort numbers to allow recursion tree pruning
	var res [][]int
	var path []int
	backtrack(candidates, &path, target, &res)
	return res
}

// @lc code=end
