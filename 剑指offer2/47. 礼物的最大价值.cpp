class Solution {
public:
    // Solution that modifies the grid inplace
    int maxValue(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < n; ++i) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }

    /*
    // Solution that does not modify the grid, with state compression
    int maxValue(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();

        // add 1 to the dimension(s) to simplify logic inside the loops
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        vector<int> dp(n + 1);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
                dp[j] = grid[i - 1][j - 1] + max(dp[j], dp[j - 1]);
            }
        }
        // return dp[m][n];
        return dp[n];
    }
    */
};
