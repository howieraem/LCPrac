/*
 * @lc app=leetcode id=52 lang=golang
 *
 * [52] N-Queens II
 */

// @lc code=start
func backtrack(r, colAvailMask, diagAvailMask, antidiagAvailMask, n int) int {
	if r == n {
		return 1
	}

	ans := 0
	for c := 0; c < n; c++ {
		diagIdx := r + c
		antidiagIdx := n - 1 - r + c

		// Check if the dimensions at the corresponding indices are available, i.e.
		// no other queens on the same column, diagonal or antidiagonal.
		if ((colAvailMask >> c) & (diagAvailMask >> diagIdx) & (antidiagAvailMask >> antidiagIdx) & 1) == 1 {
			// Set the dimensions at the corresponding indices unavailable.
			// The bitwise NOT operator in Go is `^`.
			colAvailMask &= ^(1 << c)
			diagAvailMask &= ^(1 << diagIdx)
			antidiagAvailMask &= ^(1 << antidiagIdx)

			ans += backtrack(r+1, colAvailMask, diagAvailMask, antidiagAvailMask, n)

			// Undo
			colAvailMask |= (1 << c)
			diagAvailMask |= (1 << diagIdx)
			antidiagAvailMask |= (1 << antidiagIdx)
		}
	}
	return ans
}

// T: O(n!)
// S: O(n) recursion stack
func totalNQueens(n int) int {
	nDiags := (n << 1) - 1

	// If i-th bit is 1, then the i-th dimension is available for placing a queen
	colAvailMask := (1 << n) - 1
	diagAvailMask := (1 << nDiags) - 1
	antidiagAvailMask := diagAvailMask

	return backtrack(0, colAvailMask, diagAvailMask, antidiagAvailMask, n)
}

// @lc code=end

