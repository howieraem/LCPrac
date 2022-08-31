/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int longestSubsequence(vector<int>& arr, int difference) {
        std::unordered_map<int, int> dp;

        int ans = 1;
        for (const auto& x : arr) {
            // dp[x] = dp[x - difference] + 1
            auto it = dp.find(x - difference);
            if (it == dp.end()) {
                dp[x] = 1;
            } else {
                int new_len = it->second + 1;
                dp[x] = new_len;
                ans = std::max(ans, new_len);
            }
        }
        return ans;
    }
};
// @lc code=end

