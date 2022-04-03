/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */
#include <algorithm>

// @lc code=start
class Solution {
public:
    // Mathematical solution
    // T: O(1)
    // S: O(1)
    // bool divisorGame(int N) {
    //     return !(N & 1);  // N % 2 == 0
    // }

    // DP solution
    // T: O(N ^ 2)
    // S: O(N)
    bool divisorGame(int N) {
        bool dp[N + 1];
        std::fill_n(dp, N + 1, false);
        
        for (int n = 2; n <= N; ++n) {
            for (int x = 1; x < n; ++x) {
                if (n % x == 0 && !dp[n - x]) {
                    dp[n] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
// @lc code=end

