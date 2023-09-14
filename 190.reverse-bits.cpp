/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    // T: O(s), s := no. of bits
    // S: O(1)
    uint32_t reverseBits(uint32_t n) {
        // if (!n) return n;
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end

