/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    bool validPalindrome(string s) {
        const int n = s.size();
        int l, r;
        for (l = 0, r = n - 1; l < r; ++l, --r) {
            if (s[l] != s[r]) {
                // Skip either the current left character or the right character
                // and determine whether the remaining substring is a palindrome.
                return isPalindrome(s, l + 1, r, n) || isPalindrome(s, l, r - 1, n);
            }
        }
        return true;
    }

private:
    bool isPalindrome(const string &s, int l, int r, const int &n) {
        for (; l < r; ++l, --r) {
            if (s[l] != s[r])  return false;
        }
        return true;
    }
};
// @lc code=end

