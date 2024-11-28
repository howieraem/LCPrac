/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Math
    // T: O(n)
    // S: O(1)
    int findNumbers(vector<int>& nums) {
        int ans = 0;

        for (const int& x : nums) {
            // if number range unknown
            // ans += (int)std::log10(x) & 1;

            // if number range known
            ans += (10 <= x && x < 100) || (1000 <= x && x < 10000) || x == 100000;
        }

        return ans;
    }
};
// @lc code=end

