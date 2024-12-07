/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // KMP
    // Variant of rotated string
    // T: O(n)
    // S: O(n)
    bool repeatedSubstringPattern(string s) {
        // Concat s to itself, and then remove the 1st and last chars 
        // ss = (s + s)[1:-1]
        // This removes the first and the last patterns (if any) in ss
        string ss = s.substr(1) + s.substr(0, s.size() - 1);

        // If s is still a substring of ss, then s must be consist of the same repeated pattern.
        // When matching the last periodic pattern of s, it must be checked against the second 
        // half of ss (which may or may not contain the first periodic pattern).
        // Example: 
        // Suppose s = sa + sb + sc + sd
        // ss = sa' + sb + sc + sd + sa + sb + sc + sd'
        // Matching:   s = sa + sb + sc + sd
        // If sa = sc, sb = sd, sc = sa, sd = sb,
        // Then sa = sb = sc = sd (transitive equalities), found repeated pattern
        return is_substr(ss, s);
    }

private:
    bool is_substr(const string& s, const string& t) {
        // Search for t in s with KMP
        const int m = t.size();
        vector<int> lps(m);
        int i = 1; 
        int j = 0;
        while (i < m) {
            // compute for needle[i:j+1]
            if (t[i] == t[j]) {
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
            if (s[i] == t[j]) {
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

