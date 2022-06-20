/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(min(n1, n2))
    // S: O(min(n1, n2)) recursion stack
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) {
            std::swap(str1, str2);
        }
        if (str2.empty()) return str1;
        if (str1.substr(0, str2.size()) != str2) return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};
// @lc code=end

