/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
    static const inline vector<vector<int>> NEXT_IDS = {
        {4, 6},
        {6, 8},
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
    // T: O(n)
    // S: O(1)
    int knightDialer(int n) {
        // Base case
        vector<int> cur(10, 1);
        n -= 1;

        while (n--) {
            vector<int> next(10, 0);
            for (int i = 0; i < 10; ++i) {
                for (const auto& j : NEXT_IDS[i]) {
                    next[j] = (cur[i] % F + next[j] % F) % F;
                }
            }
            cur = next;
        }

        int ans = 0;
        for (const auto &num : cur) {
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

