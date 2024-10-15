/*
 * @lc app=leetcode id=340 lang=cpp
 *
 * [340] Longest Substring with At Most K Distinct Characters
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // Sliding window
    // T: O(len(s))
    // S: O(alpha_size)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> cnts(CHAR_MAX - CHAR_MIN + 1);  // Extended ASCII, 256
        int n_uniq = 0;
        int ans = 0;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            n_uniq += (cnts[s[r] - CHAR_MIN]++ == 0);
            while (n_uniq > k) {
                n_uniq -= (--cnts[s[l++] - CHAR_MIN] == 0);
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};
// @lc code=end

