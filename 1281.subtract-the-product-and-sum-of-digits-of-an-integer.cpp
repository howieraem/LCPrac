/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start
class Solution {
public:
    // Math
    // T: O(log(n))
    // S: O(1)
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;

        while (n != 0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }

        return product - sum;
    }
};
// @lc code=end

