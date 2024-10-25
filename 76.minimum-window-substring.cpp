/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
#define ALPHA_SIZE 128  // could be 256 for signed char in C++

class Solution {
public:
    // T: O(m + n), m := len(s), n := len(t)
    // S: O(s), s := alphabet size
    string minWindow(string s, string t) {
        vector<int> cnts(ALPHA_SIZE, 0);
        for (const auto& c : t) {
            ++cnts[c];
        }

        int n_incl_chars = 0; 
        int ans_begin = 0; 
        int ans_len = INT_MAX;

        // Sliding window. Note that if some chars exist in s but not t,
        // the corresponding elements in `cnt` can become negative. Also,
        // duplicates in t must be considered too (i.e. there need to be
        // at least the count of chars in the substring of s).
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            // Increment the number of types of chars included if 
            // the count of char at s[r] is non-negative.
            // If a char in s is not in t, it is possible that cnts[s[r]] drops below 0.
            n_incl_chars += (cnts[s[r]]-- > 0);

            // Try shifting the left boundary (shrinking the window) if
            // all characters in t have been included.
            while (n_incl_chars == t.size()) {
                int cur_len = r - l + 1;
                if (cur_len < ans_len) {
                    // Update answer
                    ans_len = cur_len;
                    ans_begin = l;
                }

                n_incl_chars -= (++cnts[s[l]] > 0);
                ++l;
            }
        }

        return ans_len == INT_MAX ? "" : s.substr(ans_begin, ans_len);
    }
};
// @lc code=end

