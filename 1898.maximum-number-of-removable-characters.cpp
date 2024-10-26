/*
 * @lc app=leetcode id=1898 lang=cpp
 *
 * [1898] Maximum Number of Removable Characters
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
    // T: O(max(len(s), len(p)))
    // S: O(1)
    bool is_subseq(const string& s, const string& p) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < p.size()) {
            if (s[i] == p[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        return j == p.size();
    }

public:
    // Binary search (rightmost) max removable chars
    // T: O((len(s) + len(p)) * log(len(removable)))
    // S: O(len(s))
    int maximumRemovals(string s, string p, vector<int>& removable) {
        // Range for binary search
        int l = 0;   // minimum: not removing
        int r = removable.size() - 1;   // maximum: remove chars at all provided positions

        string s_copy = s;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            // temp mark removal
            for (int i = l; i <= m; ++i) {
                s_copy[removable[i]] = '*';
            }

            if (is_subseq(s_copy, p)) {
                l = m + 1;
            } else {
                r = m - 1;
                // revert mark removal
                for (int i = l; i <= m; ++i) {
                    s_copy[removable[i]] = s[removable[i]];
                }
            }
        }
        return r + 1;  // add 1 because i <= m rather than i < m above?
    }
};
// @lc code=end

