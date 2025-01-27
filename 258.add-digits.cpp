/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    // Math: digit root
    // T: O(1) assuming modulo is O(1)
    // S: O(1)
    int addDigits(int num) {
        int mod9 = num % 9;
        return mod9 == 0 ? (num == 0 ? 0 : 9) : mod9;
        // Example: A 4-digit number ABCD 
        //   = 1000 * A + 100 * B + 10 * C + D 
        //   = (A + B + C + D) + 9 * (111 * A + 11 * B + C)
        // So ABCD mod 9 = A + B + C + D
    }
};
// @lc code=end

