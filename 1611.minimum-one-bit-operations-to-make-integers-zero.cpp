/*
 * @lc app=leetcode id=1611 lang=cpp
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
 */

// @lc code=start
class Solution {
public:
    /*
    // With Gray code (格雷码)
    int minimumOneBitOperations(int n) {
        int ans = 0;
        while (n) {
            ans ^= n;
            n >>= 1;
        }
        return ans;
    }
    */

    int minimumOneBitOperations(int n) {
        if (!n)  return 0;
        // __builtin_clz() counts the number of leading zeros
        int pos = 32 - __builtin_clz(n) - 1;         // only works with 32-bit int
        return (1 << (pos + 1)) - 1 - minimumOneBitOperations(n ^ (1 << pos));
    }
};
// @lc code=end

