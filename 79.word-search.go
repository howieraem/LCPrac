/*
 * @lc app=leetcode id=79 lang=golang
 *
 * [79] Word Search
 */
package lc

// @lc code=start
var dirn = [5]int{1, 0, -1, 0, 1}

func backtrack(board [][]byte, r int, c int, word string, i int) bool {
	if i == len(word) {
		return true
	}

	if r < 0 || r >= len(board) || c < 0 || c >= len(board[r]) || board[r][c] != word[i] {
		return false
	}

	board[r][c] = 0
	for d := 0; d < 4; d++ {
		if backtrack(board, r+dirn[d], c+dirn[d+1], word, i+1) {
			return true
		}
	}
	board[r][c] = word[i]
	return false
}

// T: O(m * n * 3 ^ len(word))
// S: O(len(word))
func exist(board [][]byte, word string) bool {
	for r := range board {
		for c := range board[r] {
			if backtrack(board, r, c, word, 0) {
				return true
			}
		}
	}
	return false
}

// @lc code=end
