/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
    // Define the knight's reachable neighbors for each numeric cell 
    static const inline vector<vector<int>> NEXT_IDS {
        {4, 6},  // cell 0
        {6, 8},  // cell 1
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    static const int F = 1000000007;

public:
    // 2D DP + Graph
    // T: O(n * E), E := number of edges
    // S: O(V)
    int knightDialer(int n) {
        if (n <= 0) {
            return 0;
        }

        // dp[n][i] means the number of distinct phone numbers 
        // with length n starting with cell i - 1.
        // As dp[n][...] only depends on dp[n - 1][...], compress states.
        // Base case dp[1][i] = 1.
        vector<int> dp_cur(10, 1);
        n -= 1;

        while (n-- > 0) {
            vector<int> dp_next(10, 0);
            for (int i = 0; i < 10; ++i) {
                for (const auto& j : NEXT_IDS[i]) {
                    // dp[n][j] = sum(dp[n - 1][i]) where i->j is a valid edge
                    // (a + b) % m = (a % m + b % m) % m
                    dp_next[j] = (dp_cur[i] % F + dp_next[j] % F) % F;
                }
            }
            dp_cur = std::move(dp_next);
        }

        // A phone number can start with any digits, so sum them up
        int ans = 0;
        for (const auto &num : dp_cur) {
            ans = (ans % F + num % F) % F;
        }
        return ans;
    }

    // The power of matrix reveals the number of walks in an undirected graph.
    // https://math.stackexchange.com/questions/1890620/finding-path-lengths-by-the-power-of-adjacency-matrix-of-an-undirected-graph
    // The solution is thus sum([1,1,1,1,1,1,1,1,1,1] * A ^ (n - 1)).
    // Exponentiation by squaring (快速幂) reduces time complexity of x ^ n to O(log(n)).
    // x ^ n = x * (x ^ 2) ^ ((n - 1) / 2) if n is odd else (x ^ 2) ^ (n / 2)
    // T: O(log(n))
    // S: O(1)
    // See code in Python.
};
// @lc code=end

