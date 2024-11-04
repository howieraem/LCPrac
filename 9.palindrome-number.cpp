/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    // T: O(log10(x))
    // S: O(1)
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            // x < 0 or (x != 0 and x ends with 0)
            return false;
        }

        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        
        // Case 1: x has an even number of digits, see if x equals reverse
        // Case 2: x has an odd number of digits, divide reverse by 10 to eliminate that middle digit and then compare
        return x == reverse || x == reverse / 10;
    }
};
// @lc code=end

