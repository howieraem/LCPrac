/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start
class Solution {
    static const int K = 1;

public:
    // T: O(log(n))
    // S: O(1)
    int countDigitOne(int n) {
        int ans = 0;
        long base = 1;

        while (base <= n) {
            // Iterate one's place, ten's place, hundred's place, etc.
            long cur = (n / base) % 10,     // digit at `log10(base) + 1`th place from the smallest digit
                 high = n / (base * 10);    // digits in front of `cur` (prefix)

            if (cur > K)  ans += (high + 1) * base;
            else if (cur == K)  ans += high * base + (n - n / base * base) + 1;
            else  ans += high * base;

            base *= 10;
        }
        return ans;
    }
};
// @lc code=end

