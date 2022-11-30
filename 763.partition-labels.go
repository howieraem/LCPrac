/*
 * @lc app=leetcode id=763 lang=golang
 *
 * [763] Partition Labels
 */

// @lc code=start
// T: O(n)
// S: O(s), s := alphabet size
func partitionLabels(s string) []int {
	// Find the index of the last appearance of each kind of character
	var lastAppearIdx [26]int
	for i, c := range s {
		lastAppearIdx[c-'a'] = i
	}

	var res []int // part lengths
	partStart := 0
	partEnd := 0

	// Greedy
	for i, c := range s {
		if partEnd < lastAppearIdx[c-'a'] {
			// This ensures rear parts will not contain chars
			// appearing in front parts
			partEnd = lastAppearIdx[c-'a']
		}

		if i == partEnd {
			// Partition as many as possible, so just partition
			// at the last appearance of some kind of character.
			res = append(res, partEnd-partStart+1)
			partStart = partEnd + 1
		}
	}

	return res
}

// @lc code=end

