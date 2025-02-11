/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // State machine + two pointers
    // T: O(n)
    // S: O(1)
    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }
        
        // trim leading and trailing spaces
        int i = 0;
        while (s[i] == ' ') {
            ++i;
        }
        int end = s.size() - 1;
        while (end >= i && s[end] == ' ') {
            --end;
        }

        bool seen_num = false;
        bool seen_dot = false;
        bool seen_e = false;
        while (i <= end) {
            const char& c = s[i];
            if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (c == '.') {
                if (seen_dot || seen_e) {
                    return false;
                }
                seen_dot = true;
            } else if (c == 'e' || c == 'E') {
                if (seen_e || !seen_num) {
                    return false;
                }
                seen_e = true;
                seen_num = false;   // prepare for checking digits behind char e
            } else if ('0' <= c && c <= '9') {
                seen_num = true;
            } else {
                return false;
            }
            ++i;
        }
        
        return seen_num;
    }
};
// @lc code=end

