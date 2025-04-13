/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // 2D DP & 1D DP
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    int minCut(string s) {
        const size_t n = s.size();
        if (n <= 1) {
            return 0;
        }

        // is_palindrome[i][j] means whether s[i...j] is a palindrome
        // cuts[i] means the minimum number of cuts to make all substrings of s[...i] palindromic 
        vector<vector<uint8_t>> is_palindrome(n, vector<uint8_t>(n, 0));  // avoid using vector<bool>
        vector<size_t> cuts(n, 0);
        for (size_t r = 0; r < n; ++r) {
            size_t cut = n;
            for (size_t l = 0; l <= r; ++l) {
                if (s[l] == s[r] && (r - l <= 2 || is_palindrome[l + 1][r - 1])) {
                    is_palindrome[l][r] = 1;
                    cut = l == 0 ? 0 : std::min(cut, cuts[l - 1] + 1);
                }
            }
            cuts[r] = cut;
        }
        return (int)cuts.back();
    }
};
// @lc code=end

