/*
 * @lc app=leetcode id=73 lang=golang
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
// T: O(m * n)
// S: O(1)
func setZeroes(matrix [][]int) {
	m := len(matrix)
	n := len(matrix[0])

	row0Flag := false
	col0Flag := false
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == 0 {
				// Use the first row and the first col to mark existence(s) of zero.
				matrix[i][0] = 0
				matrix[0][j] = 0

				// Use a row flag and a col flag to check if the first row and/or the first column
				// should also be zeroed after processing all other rows and columns.
				if i == 0 {
					row0Flag = true
				}

				if j == 0 {
					col0Flag = true
				}
			}
		}
	}

	// Process entries except the first row and the first column based on
	// info stored in the first row and the first column
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if matrix[i][0] == 0 || matrix[0][j] == 0 {
				matrix[i][j] = 0
			}
		}
	}

	// Now zero the first row and/or the first column if needed
	if row0Flag {
		for j := 0; j < n; j++ {
			matrix[0][j] = 0
		}
	}

	if col0Flag {
		for i := 0; i < m; i++ {
			matrix[i][0] = 0
		}
	}
}

// @lc code=end

