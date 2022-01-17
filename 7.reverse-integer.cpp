/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
#include <limits>

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        const int MAX = INT_MAX / 10, 
                  MIN = INT_MIN / 10,
                  MAX_R = INT_MAX % 10,
                  MIN_R = INT_MIN % 10;
        
        while (x) {
            int u = x % 10;
            if (ans > MAX || (ans == MAX && u > MAX_R) || ans < MIN || (ans == MIN && u < MIN_R)) {
                // overflow
                return 0;
            }
            ans *= 10;
            ans += u;
            x /= 10;
        }

        return ans;
    }
};
// @lc code=end

