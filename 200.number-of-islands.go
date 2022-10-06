/*
 * @lc app=leetcode id=200 lang=golang
 *
 * [200] Number of Islands
 */
package lc

// @lc code=start
var dirn = [5]int{1, 0, -1, 0, 1}

/*
// Perform BFS for each unvisited island cell
type Pos struct {
	r, c int
}

// T: O(m * n)
// S: O(m * n)
func numIslands(grid [][]byte) int {
	m := len(grid)
	n := len(grid[0])

	q := make(chan *Pos, m*n)
	ans := 0

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '1' {
				ans++

				q <- &Pos{i, j}
				grid[i][j] = '0'

				for len(q) != 0 {
					pos := <-q

					for d := 0; d < 4; d++ {
						nr := pos.r + dirn[d]
						nc := pos.c + dirn[d+1]
						if 0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == '1' {
							q <- &Pos{nr, nc}
							grid[nr][nc] = '0'
						}
					}
				}
			}
		}
	}
	return ans
}
*/

// DFS
func dfs(grid *[][]byte, r int, c int) {
	if r < 0 || r >= len(*grid) || c < 0 || c >= len((*grid)[r]) || (*grid)[r][c] == '0' {
		return
	}
	(*grid)[r][c] = '0'
	for d := 0; d < 4; d++ {
		dfs(grid, r+dirn[d], c+dirn[d+1])
	}
}

// T: O(m * n)
// S: O(m * n) recursion stack
func numIslands(grid [][]byte) int {
	ans := 0
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == '1' {
				ans++
				dfs(&grid, i, j)
			}
		}
	}
	return ans
}

// @lc code=end
