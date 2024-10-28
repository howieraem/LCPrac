/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // 1D DP
    // T: O(n)
    // S: O(1)
    int minFlipsMonoIncr(string s) {
        int cnt_one = 0;
        int dp = 0;
        for (const auto& c : s) {
            bool is_one = (c == '1');
            cnt_one += is_one;
            dp += !is_one;

            // Suppose s[:i-1] is already monotone increasing, if
            // s[i] is anti-pattern, either flip zero to one, or 
            // flip all seen ones to zeros, whichever costs less.
            dp = std::min(dp, cnt_one);
        }
        return dp;
    }
};
// @lc code=end

