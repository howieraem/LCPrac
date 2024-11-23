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
    // Sliding window + Hash map
    // T: O(n)
    // S: O(alpha_size), alpha_size := 26
    bool checkInclusion(string s1, string s2) {
        const int m = s1.size(), n = s2.size();
        if (m > n) {
            return false;  // trivial
        }

        vector<int> cnts(26, 0);
        for (const auto& c : s1) {
            ++cnts[c - 'a'];
        }

        // Decrement cnts[s2[r]] and increment cnts[s2[l]].
        // If there exists a permutation, then all cnts should be zero. 
        int l = 0;
        for (int r = 0; r < n; ++r) {
            --cnts[s2[r] - 'a'];

            if (r - l + 1 < m) {
                // window size too small
                continue;
            }

            // Window size is fixed at m from this iteration on. 
            // Check if the windowed substring is a permutation of s1.
            if (std::all_of(cnts.cbegin(), cnts.cend(), [] (const int& cnt) { return cnt == 0; })) {
                return true;
            }
            ++cnts[s2[l++] - 'a'];
        }
        return false;
    }
};
// @lc code=end

