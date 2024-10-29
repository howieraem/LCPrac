/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // Greedy
    // T: O(n)
    // S: O(1)
    bool checkValidString(string s) {
        // upper bound of the number of '(' not yet matched with ')'
        int upper = 0;

        // lower bound of the number of '(' not yet matched with ')', must be non-negative
        int lower = 0;

        for (const auto& c : s) {
            if (c == '(') {
                ++upper;
                ++lower;
            } else if (c == ')') {
                --upper;
                lower -= (lower > 0);  // lower = max(lower - 1, 0), keep lower bound >= 0
            } else { // c == '*'
                ++upper;                // if '*' represents '('
                lower -= (lower > 0);   // if '*' represents ')', lower = max(lower - 1, 0), and keep lower bound >= 0
            }

            if (upper < 0) {
                // Since lower <= upper, there must be insufficient '(' to match ')', 
                // regardless of any '*' yet to be iterated
                return false;
            }
        }

        // Finally, the number of possible '(' must equal the number of possible ')'.
        // If lower > 0, it means there must be some '(' not yet matched with ')'.
        return lower == 0;
    }
};
// @lc code=end

