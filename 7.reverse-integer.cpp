/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(log10(x))
    // S: O(1)
    int reverse(int x) {
        const int MAX = INT_MAX / 10;
        const int MIN = INT_MIN / 10;
        const int MAX_R = INT_MAX % 10;
        const int MIN_R = INT_MIN % 10;

        int ans = 0;
        while (x != 0) {
            int r = x % 10; // least significant digit
            if (ans > MAX || (ans == MAX && r > MAX_R) || ans < MIN || (ans == MIN && r < MIN_R)) {
                // overflow
                return 0;
            }
            ans = ans * 10 + r;
            x /= 10;
        }

        return ans;
    }
};
// @lc code=end

