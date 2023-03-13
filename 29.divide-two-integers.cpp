/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(log(dividend) * log(divisor))
    // S: O(1)
    int divide(int dividend, int divisor) {
        // Take special care when only 32-bit ints are allowed.
        if (divisor == 0) return INT_MAX;
        if (divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;
        
        int ans = 0;
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            if (divisor == 1) return INT_MIN;
            
            dividend += abs(divisor);
            ans = 1;
        }

        bool is_neg = (dividend > 0) ^ (divisor > 0);
        dividend = abs(dividend);
        divisor = abs(divisor);

        // Idea: the quotient of a division is just the number of 
        // times that we can subtract the divisor from the dividend 
        // without making it negative.
        while (dividend >= divisor) {
            int temp = divisor;
            int mult = 1;
            // while (dividend >= (temp << 1) && (temp << 1) > 0) {
            while (dividend - temp >= temp) {  // temp << 1 may overflow
                temp <<= 1;
                mult <<= 1;
            }

            dividend -= temp;
            ans += mult;
        }

        return is_neg ? -ans : ans;
    }
};
// @lc code=end

