/*
 * @lc app=leetcode id=1139 lang=golang
 *
 * [1139] Largest 1-Bordered Square
 */
package lc

// @lc code=start
// 2D DP + Matrix + Geometry
// T: O(m * n * min(m, n))
// S: O(m * n)
func largest1BorderedSquare(grid [][]int) int {
	m := len(grid)
	if m == 0 {
		return 0
	}
	n := len(grid[0])
	if n == 0 {
		return 0
	}

	hSizes := make([][]int, m)
	vSizes := make([][]int, m)
	for i := 0; i < m; i++ {
		hSizes[i] = make([]int, n)
		vSizes[i] = make([]int, n)

		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				continue
			}

			if j == 0 {
				hSizes[i][j] = 1
			} else {
				hSizes[i][j] = hSizes[i][j-1] + 1
			}

			if i == 0 {
				vSizes[i][j] = 1
			} else {
				vSizes[i][j] = vSizes[i-1][j] + 1
			}
		}
	}

	var side int
	if m > n {
		side = n
	} else {
		side = m
	}

	for side > 0 {
		for i := 0; i < m-side+1; i++ {
			for j := 0; j < n-side+1; j++ {
				if hSizes[i][j+side-1] >= side && hSizes[i+side-1][j+side-1] >= side &&
					vSizes[i+side-1][j] >= side && vSizes[i+side-1][j+side-1] >= side {
					// Ensure it can form a valid square
					return side * side
				}
			}
		}
		side--
	}

	return 0
}

// @lc code=end
