/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // Math + two pointers
    // T: O(n)
    // S: O(1)
    string addStrings(string num1, string num2) {
        string res;
        res.reserve(std::max(num1.size(), num2.size()) + 1);

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry == 1) {
            carry += i >= 0 ? num1[i--] - '0' : 0;
            carry += j >= 0 ? num2[j--] - '0' : 0;
            res.push_back((carry % 10) + '0');
            carry /= 10;
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

