/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // Bit manipulation
    // T: O(n)
    // S: O(1)
    char findTheDifference(string s, string t) {
        char ans = 0;

        // Idea: chars appear in both s and t will cancel out after XOR

        for (const auto& c : s) {
            ans ^= c;
        }

        for (const auto& c : t) {
            ans ^= c;
        }

        return ans;
    }
};
// @lc code=end

