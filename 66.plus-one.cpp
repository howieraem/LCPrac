/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n) worst case
    // S: O(1)
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i] %= 10;
            if (digits[i] != 0) {
                // No carry, done
                return digits;
            }
        }

        // digits[0] = 0 here, for cases like 99 and 999
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
// @lc code=end

