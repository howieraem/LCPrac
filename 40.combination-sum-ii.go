/*
 * @lc app=leetcode id=40 lang=golang
 *
 * [40] Combination Sum II
 */
package lc

import "sort"

// @lc code=start
func backtrack(candidates []int, begin int, path *[]int, remain int, res *[][]int) {
	if remain == 0 {
		combo := make([]int, len(*path))
		copy(combo, *path)
		*res = append(*res, combo)
	}
	// Each number in candidates may only be used once in the combination.
	for i := begin; i < len(candidates); i++ {
		num := candidates[i]
		if num > remain {
			// IMPORTANT prune: stop if exceeding target
			break
		}
		if i > begin && candidates[i-1] == num {
			// IMPORTANT: skip duplicates
			continue
		}
		*path = append(*path, num)
		backtrack(candidates, i+1, path, remain-num, res)
		*path = (*path)[:len(*path)-1]
	}
}

// T: O(len(candidates) ^ target) worst case
// S: O(len(candidates) * target) ?
func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	var res [][]int
	var path []int
	backtrack(candidates, 0, &path, target, &res)
	return res
}

// @lc code=end
