/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // Memoized DFS (top-down 2D DP)
    // T: O(m * n)
    // S: O(m * n)
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        // Use memo dfs if state transitions cannot be well formulated or hard to formulate the order of updating dp table
        // like this (with 2D coordinates and max 4 directions)
        vector<vector<int>> memo(m, vector<int>(n, 0));  
        int ans = 0;

        // Start dfs from every cell (some intermediate results from previous cells can be reused)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }

private:
    static constexpr int DIRN[] {-1, 0, 1, 0, -1};

    static int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo) {
        if (memo[i][j] > 0) {
            // state visited, reuse
            return memo[i][j];
        }
        ++memo[i][j];
        for (int d = 0; d < 4; ++d) {
            int ni = i + DIRN[d], nj = j + DIRN[d + 1];
            if (ni >= 0 && ni < matrix.size() && 
                nj >= 0 && nj < matrix[i].size() && 
                matrix[ni][nj] > matrix[i][j]) {
                memo[i][j] = max(memo[i][j], dfs(matrix, ni, nj, memo) + 1);
            }
        }
        return memo[i][j];
    }
};
// @lc code=end

