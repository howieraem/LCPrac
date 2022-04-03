/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1
    // T: O(m * n)
    // S: O(m * n)
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.size(), n = text2.size();
        
        // dp[i][j] means the longest common subsequence for text1[:i] and text2[:j].
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (text1[i] == text2[j]) {
                    // Current characters equal, increment length of the previous longest common subseq
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    // Current characters not equal, determine which string sequence is longer
                    dp[i + 1][j + 1] = max(
                        dp[i][j + 1],   // text1[:i] and text2[:j+1] have longer common subseq. (use current character in text2)
                        dp[i + 1][j]    // text1[:i+1] and text2[:j] have longer common subseq. (use current character in text1)
                    );
                }
            }
        }
        return dp[m][n];
    }
    */

    // Solution 2, state compression
    // T: O(m * n)
    // S: O(min(m, n))
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.size(), n = text2.size();
        if (m < n) {
            // Make the second argument the shorter string
            return longestCommonSubsequence(text2, text1);
        }
        
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < m; ++i) {
            int preRow = 0, preRowpreCol = 0;
            for (int j = 0; j < n; ++j) {
                preRowpreCol = preRow;
                preRow = dp[j + 1];
                if (text1[i] == text2[j]) {
                    dp[j + 1] = preRowpreCol + 1;
                } else {
                    dp[j + 1] = max(dp[j], preRow);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

