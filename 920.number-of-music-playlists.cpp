/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * goal)
    // S: O(n * goal)
    int numMusicPlaylists(int n, int goal, int k) {
        const long long MOD = 1000000007LL;

        // dp[i][j] means the number of playlists for i different songs and j songs
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, 0LL));

        // base case: dp[n][n] = n! and dp[0][l] = 0
        dp[1][1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i][i] = (dp[i - 1][i - 1] * i) % MOD;  // goal > n, no need to check index out of bound
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= goal; ++j) {
                // 1st term: the added song is an old song
                //     Using i numbers in j - 1 position, if open a new position, the possible inserted value 
                //     can be only selected from i - k numbers as the nearest k numbers cannot be used.
                // 2nd term: the added song is a new song
                //     Using i - 1 numbers in j - 1 position, the inserted number must be the remaining number. 
                //     Since we can use any i - 1 numbers in i numbers, we have i different combinations.
                dp[i][j] = ((dp[i][j - 1] * std::max(0, i - k)) % MOD + (dp[i - 1][j - 1] * i) % MOD) % MOD;
            }
        }
        return dp[n][goal];
    }
};
// @lc code=end

