/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start
class Solution {
public:
    // Question: find the n-th character (digit) in 
    // "123456789101112131415161718192021...".
    int findNthDigit(int n) {
        // Step 1. Find how many digits the target number string has.
        // Pattern:
        // range(1, 10) includes 9 1-digit numbers;
        // range(10, 100) includes 90 2-digit numbers;
        // range(100, 1000) include 900 3-digit numbers;
        // ...

        // Step 2. Find the value of the target number (at the end of the 
        // entire number string) where the n-th digit is in. 
        // For example, when n = 10 or 11, this number is "10".

        // The following combines steps 1 and 2:
        long n_numbers = 9, digits = 1, target = 1;
        while (n - n_numbers * digits > 0) {
            n -= n_numbers * digits;
            n_numbers *= 10;
            ++digits;
            target *= 10;
        }
        target += (n - 1) / digits;

        // Step 3. Find the n-th digit in the entire number string, 
        // or equivalently the corresponding digit in `target`.

        // Intuitive approach: 
        // std::string s = std::to_string(target);
        // return s[(n - 1) % digits] - '0';

        // Alternative approach, without string conversion:
        int idx = n % digits;
        if (!idx) idx = digits;
        for (int i = idx; i < digits; ++i) {
            target /= 10;
        }
        return target % 10;
    }
};
// @lc code=end

