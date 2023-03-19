/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // Greedy + two pointer
    // T: O(m * n) worst case
    // S: O(1)
    bool isMatch(string s, string p) {
        int i = 0, j = 0; 
        int j_star = -1;  // last idx of '*' in p
        int last_match = -1; // idx of the previously matched char in s when '*' encountered in p

        // Explanation: 
        // https://leetcode.com/problems/wildcard-matching/solutions/17810/linear-runtime-and-constant-space-solution/comments/116559
        while (i < s.size()) {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                // single char match
                ++i; ++j;
            } else if (j < p.size() && p[j] == '*') {
                j_star = j++;
                last_match = i;
            } else if (j_star != -1) {
                // encountered '*' in p, move string pointer
                j = j_star + 1;
                i = ++last_match;
            } else {
                // no last '*' found, can't match chars
                return false;
            }
        }

        // check for remaining chars in pattern
        while (j < p.size() && p[j] == '*') {
            ++j;
        }

        return j == p.size();
    }

    // Besides: DP solution, takes extra space O(m * n) or with state compression O(m)
    //   if p[j] != '*', dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?')
    //   if p[j] == '*', dp[i][j] = dp[i][j - 1] || dp[i - 1][j]
    //   ret dp[m][n]
};
// @lc code=end

