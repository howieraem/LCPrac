/*
 * @lc app=leetcode id=781 lang=golang
 *
 * [781] Rabbits in Forest
 */
package lc

// @lc code=start
// Equivalent to int(math.Ceil(float(x) / float(y)))
func ceilDiv(x, y int) int {
	return (x + y - 1) / y
}

// Math + Greedy + Hash Map
// T: O(n)
// S: O(n)
func numRabbits(answers []int) int {
	szCnts := make(map[int]int)
	for _, sz := range answers {
		szCnts[sz]++
	}

	ans := 0
	for sz, cnt := range szCnts {
		// There are sz+1 same kind rabbits (because each entry in original `answers` excludes self)
		// If `cnt` rabbits answer `sz`:
		//   - If cnt % (sz+1) == 0, we need cnt / (sz+1) groups of (sz+1) rabbits.
		//   - If cnt % (sz+1) != 0, we need cnt / (sz+1) + 1 groups of (sz+1) rabbits.
		// So the minimum no. of groups is `ceil(cnt / (sz+1))`.
		// Multiply the minimum no. of groups by the group size to get the answer.
		ans += ceilDiv(cnt, sz+1) * (sz + 1)
	}
	return ans
}

// @lc code=end
