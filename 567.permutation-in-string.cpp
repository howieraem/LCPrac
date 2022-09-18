/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(s), s := 26
    bool checkInclusion(string s1, string s2) {
        const int m = s1.size(), n = s2.size();
        if (m > n) return false;  // trivial

        vector<int> cnts(26, 0);
        for (const auto& c : s1) {
            ++cnts[c - 'a'];
        }

        for (int l = 0, r = 0; r < n; ++r) {
            --cnts[s2[r] - 'a'];

            if (r - l + 1 < m) continue;

            // Window size should be m from now on. Check if every window is an anagram of s1
            if (std::all_of(cnts.cbegin(), cnts.cend(), [] (const int& cnt) { return cnt == 0; })) {
                return true;
            }
            ++cnts[s2[l++] - 'a'];
        }
        return false;
    }
};
// @lc code=end

