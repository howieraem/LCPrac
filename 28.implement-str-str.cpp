/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n + m) worst case, m := len(needle), n := len(haystack)
    // S: O(m)
    int strStr(string haystack, string needle) {
        const int m = needle.size();
        if (m == 0) {
            return 0;
        }

        // failure function, or longest prefix suffix (LPS)
        // longest prefix of needle (except entire needle) that matches suffix of needle
        // Worst: O(2 * m)
        int f[m];
        std::memset(f, 0, sizeof(f));
        int i = 1, j = 0;
        while (i < m) {
            // compute for needle[i:j+1]
            if (needle[i] == needle[j]) {
                f[i++] = ++j;
                // f[i] = j + 1; i++; j++;
            } else if (j > 0) {
                j = f[j - 1];
            } else {
                // f[i] = 0;
                ++i;
            }
        }
        
        // KMP
        i = j = 0;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                if (j == m - 1) {
                    return i - j;
                } else {
                    ++i; 
                    ++j;
                }
            } else {
                if (j != 0) { 
                    j = f[j - 1];
                } else {
                    ++i;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

