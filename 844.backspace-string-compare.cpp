/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(m + n)
    // S: O(1)
    bool backspaceCompare(std::string& s, std::string& t) {
        const int m = s.size(), n = t.size();
        int i = m - 1, j = n - 1, s_s_cnt = 0, t_s_cnt = 0;

        while (i >= 0 || j >= 0) {
            // Simulate the backspace ops
            while (i >= 0 && (s[i] == '#' || s_s_cnt)) {
                if (s[i] == '#')  ++s_s_cnt;
                else  --s_s_cnt;
                --i;
            }
            while (j >= 0 && (t[j] == '#' || t_s_cnt)) {
                if (t[j] == '#')  ++t_s_cnt;
                else  --t_s_cnt;
                --j;
            }

            // Check character equal
            if (i >= 0 && j >= 0 && s[i] == t[j]) {
                --i, --j;
            } else {
                return i == -1 && j == -1;
            }
        }
        return true;
    }
};
// @lc code=end

