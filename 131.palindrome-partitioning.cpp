/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * 2^n)
    // S: O(n)
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        const int n = s.size();
        
        // dp[i][j] means whether s[i:j] is a palindrome
        vector<vector<unsigned char>> dp(n, vector<unsigned char>(n, 0));  // avoid using vector<bool>

        for (int r = 0; r < n; ++r) {
            for (int l = 0; l <= r; ++l) {
                if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
                    dp[l][r] = 1;
                }
            }
        }

        vector<string> parts;
        backtrack(s, parts, 0, dp, n, res);
        return res;
    }

private:
    void backtrack(const string &s, vector<string> &parts, int start, const vector<vector<unsigned char>> &dp, const int &n, vector<vector<string>> &res) {
        if (start == n) {   
            // Append a copy
            res.push_back(parts);
            return;
        }

        for (int end = start; end < n; ++end) {
            if (dp[start][end]) {
                parts.push_back(s.substr(start, end - start + 1));
                backtrack(s, parts, end + 1, dp, n, res);
                parts.pop_back();
            }
        }
    }
};
// @lc code=end

