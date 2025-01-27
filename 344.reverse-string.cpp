/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // array + two pointers
    // T: O(n)
    // S: O(1)
    void reverseString(vector<char>& s) {
        const size_t& n = s.size();
        for (int i = 0; i < (n >> 1); ++i) {
            std::swap(s[i], s[n - 1 - i]);
        }
    }
};
// @lc code=end

