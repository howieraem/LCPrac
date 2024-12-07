/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // Greedy + hash map
    // T: O(n + alpha_size)
    // S: O(alpha_size)
    string reorganizeString(string s) {
        const int n = s.size();
        if (n == 0) {
            return s;
        }

        // Strategy: find the max freq char, fill the res at even indices,
        // then rest of the chars at the remaining indices (even first, then
        // odd)

        vector<int> freq(26);
        char max_freq_char = 'a';
        int max_freq = 0;
        for (const char& c : s) {
            if (++freq[c - 'a'] > max_freq) {
                max_freq = freq[c - 'a'];
                if (max_freq > ((n + 1) >> 1)) {
                    // impossible to rearrange
                    return "";
                }
                max_freq_char = c;
            }
        }

        string res(n, 'a');
        int p = 0;
        while (freq[max_freq_char - 'a']-- > 0) {
            res[p] = max_freq_char;
            p += 2;
        }
        for (int i = 0; i < freq.size(); ++i) {
            while (freq[i]-- > 0) {
                if (p >= n) {
                    // even index slots have been occupied,
                    // start filling at the odd indices
                    p = 1;
                }
                res[p] = (char) (i + 'a');
                p += 2;
            }
        }
        return res;
    }
};
// @lc code=end

