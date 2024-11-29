/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // Sliding window + hash map
    // T: O(n + alpha_size)
    // S: O(alpha_size)
    int countGoodSubstrings(string s) {
        const int K = 3;
        int ans = 0;
        vector<int> cnts(26);
        int n_uniq_chars = 0;

        for (int r = 0; r < s.size(); ++r) {  // shift window right pointer
            n_uniq_chars += (cnts[s[r] - 'a']++ == 0);
            if (r >= K - 1) {
                if (r >= K) {
                    // shift window left pointer
                    n_uniq_chars -= (--cnts[s[r - K] - 'a'] == 0);
                }
                ans += n_uniq_chars == K;
            }
        }

        return ans;
    }
};
// @lc code=end

