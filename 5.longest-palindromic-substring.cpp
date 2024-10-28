/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1: 2D DP
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    string longestPalindrome(string s) {
        const int n = s.size();
        // dp[i][j] means s[i...j] whether is a palindrome
        bool dp[n][n];  // avoid using vector<bool>
        for (int i = 0; i < n; ++i) {
            fill_n(dp[i], n, false);
        }

        int res_len = 1, res_start = 0;
        for (int r = 0; r < n; ++r) {
            for (int l = 0; l < r; ++l) {
                if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1])) {
                    dp[l][r] = true;  // covers base cases like dp[i][i] = true
                    if (r - l + 1 > res_len) {
                        res_len = r - l + 1;
                        res_start = l;
                    }
                }
            }
        }
        return s.substr(res_start, res_len);
    }
    */

    // Solution 2: Two pointers
    // T: O(n ^ 2)
    // S: O(1)
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n < 2)  {
            return s;
        }

        int res_len = 1, res_start = 0;

        // As a singleton character is a palindrome, try extending each character
        // to the left and to the right to form longer palindromes
        for (int i = 0; i < n - 1; ++i) {
            // odd length (start with one character)
            extendPalindrome(s, i, i, res_len, res_start);

            // even length (start with two identical characters which will be the center of the palindrome)
            if (s[i] == s[i + 1]) {
                extendPalindrome(s, i, i + 1, res_len, res_start);
            }
        }
        return s.substr(res_start, res_len);
    }

private:
    // Tries extending the palindrome s[l:r+1] to both left and right, and updates
    // the maximum length and the final start index of that palindrome
    static void extendPalindrome(string s, int l, int r, int& res_len, int& res_start) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l, ++r;
        }

        // Now l is at the left of the first character of the current palindrome
        // Therefore, the index of the first character of the current palindrome
        // is l + 1. Similar for r. 
        int new_len = r - l - 1;    // (r - 1) - (l + 1) + 1
        if (new_len > res_len) {
            res_len = new_len;
            res_start = l + 1;
        }
    }
};
// @lc code=end

