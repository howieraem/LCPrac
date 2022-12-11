/*
 * @lc app=leetcode id=54 lang=golang
 *
 * [54] Spiral Matrix
 */

// @lc code=start
// Variant of two pointers
// T: O(m * n)
// S: O(1) ignoring returned array
func spiralOrder(matrix [][]int) []int {
	m := len(matrix)
	n := len(matrix[0])

	// IMPORTANT: m rows and n columns
	left := 0
	right := n - 1
	top := 0
	bottom := m - 1

	res := make([]int, m*n)
	p := 0

	for left <= right && top <= bottom {
		for j := left; j <= right; j++ {
			res[p] = matrix[top][j]
			p++
		}

		for i := top + 1; i <= bottom; i++ {
			res[p] = matrix[i][right]
			p++
		}

		// Even numbers of rows and cols in the center remaining
		if left < right && top < bottom {
			for j := right - 1; j > left; j-- {
				res[p] = matrix[bottom][j]
				p++
			}

			for i := bottom; i > top; i-- {
				res[p] = matrix[i][left]
				p++
			}
		}

		left++
		right--
		top++
		bottom--
	}
	return res
}

// @lc code=end

