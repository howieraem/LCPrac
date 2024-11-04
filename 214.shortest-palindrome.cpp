/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */
#include <bits/stdc++.h>

using std::reverse;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // Variant of KMP
    // T: O(n)
    // S: O(n)
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string l = s + "#" + rev;   // IMPORTANT: add separator char

        // The prefix function for a string s is an array p, where p[i] is 
        // the length of the longest proper prefix of the substring s[0...i] 
        // which is also a suffix of this substring. Proper prefix of a string 
        // is a prefix that is not equal to the string itself. 
        // Base case p[0] = 0 because a string of length 1 has no proper prefixes.
        /*
        vector<int> p(l.size());
        for (int i = 1; i < l.size(); ++i) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j]) {
                j = p[j - 1];
            }
            j += l[i] == l[j];
            p[i] = j;
        }
        */
        vector<int> p(l.size());
        int i = 1; 
        int j = 0;
        while (i < l.size()) {
            // compute for l[i:j+1]
            if (l[i] == l[j]) {
                p[i++] = ++j;
                // p[i] = j + 1; i++; j++;
            } else if (j > 0) {
                j = p[j - 1];
            } else {
                // p[i] = 0;
                ++i;
            }
        }

        // Only the last value of the prefix function is meaningful here, as 
        // it shows us the largest suffix of `rev` that matches the prefix of 
        // `s`. The shortest palindrome is just adding the first (len(s) - p[-1]) 
        // characters of `rev` to `s`
        return rev.substr(0, s.size() - p.back()) + s;
    }
};
// @lc code=end

