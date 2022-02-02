/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
#include <limits>

// @lc code=start
class Solution {
public:
    // T: O(log10(x))
    // S: O(1)
    int reverse(int x) {
        int ans = 0;
        const int MAX = INT_MAX / 10, 
                  MIN = INT_MIN / 10,
                  MAX_R = INT_MAX % 10,
                  MIN_R = INT_MIN % 10;
        
        while (x) {
            int u = x % 10; // least significant digit
            if (ans > MAX || (ans == MAX && u > MAX_R) || ans < MIN || (ans == MIN && u < MIN_R)) {
                // overflow
                return 0;
            }
            ans = ans * 10 + u;
            x /= 10;
        }

        return ans;
    }
};
// @lc code=end

