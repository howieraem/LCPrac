/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int singleNumber(vector<int>& nums) {
        int seen_once = 0;
        int seen_twice = 0;
        for (int x : nums) {
            // If x not in seen_once, add x to it iff x not in seen_twice either
            // Else remove x from seen_once
            seen_once = (seen_once ^ x) & ~seen_twice;

            // If x not in seen_twice, add x to it iff x not in seen_once either
            // Else remove x from seen_twice
            seen_twice = (seen_twice ^ x) & ~seen_once;
        }
        return seen_once;  // finally left with the number that appear once
    }
};
// @lc code=end

