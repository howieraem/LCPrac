/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    // T: O(m * n * 3 ^ l), m := board height, n := board width, l := word length
    // S: O(l)
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    static constexpr int D[] {-1, 0, 1, 0, -1};

    // T: O(3 ^ l) (Though 4 adjacencies for each cell in the middle, the adjancency that is the previous step should not be counted)
    static bool backtrack(vector<vector<char>> &b, const string &w, int r, int c, int wi) {
        if (wi == w.size()) {
            return true;
        }

        // As there might only be one element in the board, we must
        // check before (rather than inside) the for loop below.
        // Otherwise, the case {board=[['a']], word="a"} will fail.
        if (r < 0 || r == b.size() || c < 0 || c == b[r].size())  return false;
        if (b[r][c] != w[wi]) {
            return false;
        }

        char tmp = b[r][c];
        b[r][c] = 0;    // mark visited
        ++wi;
        for (int d = 0; d < 4; ++d) {
            if (backtrack(b, w, r + D[d], c + D[d + 1], wi)) {
                return true;
            }
        }
        b[r][c] = tmp;  // undo visit
        return false;
    }
};
// @lc code=end

