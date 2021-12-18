/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n^3)
    // S: O(n^2)
    int maxCoins(vector<int>& nums) {
        vector<int> coins;
        coins.push_back(1);
        for (const int &num : nums) {
            if (num) {  // skip the zeros
                coins.push_back(num);
            }
        }
        coins.push_back(1);
        const int n = coins.size();

        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int k = 2; k < n; ++k) {
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(
                        dp[left][right],
                        coins[left] * coins[i] * coins[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

