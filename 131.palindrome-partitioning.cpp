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
    // T: O(n * 2 ^ n)
    // S: O(n ^ 2) for the is_palindrome 2D array
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        const int n = s.size();
        
        // is_palindrome[i][j] means whether s[i:j+1] is a palindrome.
        // Precompute this dp info to reduce time cost in backtracking.
        // In Q132, this part is essential as backtracking is not needed.
        vector<vector<uint8_t>> is_palindrome(n, vector<uint8_t>(n, 0));  // avoid using vector<bool>
        for (int r = 0; r < n; ++r) {
            for (int l = 0; l <= r; ++l) {
                if (s[l] == s[r] && (r - l <= 2 || is_palindrome[l + 1][r - 1])) {
                    is_palindrome[l][r] = 1;
                }
            }
        }

        vector<string> parts;
        backtrack(s, parts, 0, is_palindrome, res);
        return res;
    }

private:
    void backtrack(const string &s, vector<string> &parts, int begin, const vector<vector<uint8_t>> &is_palindrome, vector<vector<string>> &res) {
        if (begin == s.size()) {   
            // Append a copy
            res.push_back(parts);
            return;
        }

        for (int end = begin; end < s.size(); ++end) {
            if (is_palindrome[begin][end]) {
                parts.push_back(s.substr(begin, end - begin + 1));
                backtrack(s, parts, end + 1, is_palindrome, res);
                parts.pop_back();
            }
        }
    }
};
// @lc code=end

