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
    // T: O(m * n) ?
    // S: O(m * n)
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
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
        if (memo[i][j])  return memo[i][j];
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

