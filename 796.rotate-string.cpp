/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // KMP
    // T: O(n)
    // S: O(n)
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        s += s;  // append s to itself

        // Search for goal in the new s with KMP
        const int m = goal.size();
        vector<int> lps(m);
        int i = 1; 
        int j = 0;
        while (i < m) {
            // compute for needle[i:j+1]
            if (goal[i] == goal[j]) {
                lps[i++] = ++j;
                // lps[i] = j + 1; i++; j++;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                // lps[i] = 0;
                ++i;
            }
        }

        i = j = 0;
        while (i < s.size()) {
            if (s[i] == goal[j]) {
                if (j == m - 1) {
                    return true;
                } else {
                    ++i;
                    ++j;
                }
            } else {
                if (j > 0) { 
                    j = lps[j - 1];
                } else {
                    ++i;
                }
            }
        }
        return false;
    }
};
// @lc code=end

