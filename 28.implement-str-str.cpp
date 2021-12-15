/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n + m) worst case, m := len(needle), n := len(haystack)
    // S: O(m)
    int strStr(string haystack, string needle) {
        const int m = needle.size();
        if (!m)  return 0;
        const int n = haystack.size();
        
        // failure function
        int f[m];
        memset(f, 0, sizeof(f));
        int i = 1, j = 0;
        while (i < m) {
            if (needle[i] == needle[j]) {
                f[i++] = ++j;
                // f[i] = j + 1; i++; j++;
            } else if (j > 0) {
                j = f[j - 1];
            } else {
                ++i;
            }
        }
        
        // KMP
        i = j = 0;
        while (i < n) {
            if (haystack[i] == needle[j]) {
                if (j == m - 1)  return i - j;
                else {
                    ++i; ++j;
                }
            } else {
                if (j)  j = f[j - 1];
                else  ++i;
            }
        }
        return -1;
    }
};
// @lc code=end

