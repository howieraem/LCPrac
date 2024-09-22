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
    // T: O(n)
    // S: O(1)
    int minFlipsMonoIncr(string s) {
        int cnt_one = 0;
        int dp = 0;
        for (const auto& c : s) {
            bool is_one = (c == '1');
            cnt_one += is_one;
            dp += !is_one;

            // either flip all ones seen to zeros, or flip zeros to ones,
            // whichever costs less
            dp = std::min(dp, cnt_one);
        }
        return dp;
    }
};
// @lc code=end

