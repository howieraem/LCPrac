/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include <bits/stdc++.h>

using std::string;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 3)
    // S: O(n + len(wordDict))
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        const int n = s.size();

        // dp[i] means whether s[:i] can be segmented 
        // into a space-separated sequence of one or 
        // more dictionary words
        vector<uint8_t> dp(n + 1, 0);
        dp[0] = 1;  // IMPORTANT base case

        for (int i = 1; i <= n; ++i) {   // i can be interpreted as length of prefix of s
            for (int j = 0; j < i; ++j) {
                // dp[i] is true iff dp[j] is true and s[j:i] is in dict.
                // substr() is O(n)
                if (dp[j] && words.find(s.substr(j, i - j)) != words.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

