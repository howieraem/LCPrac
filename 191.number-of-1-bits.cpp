/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t x) {
        // return __builtin_popcount(n);
        int ans = 0;

        /*
        // Intuitive approach: iterate bits until all bits zero,
        // T: O(m), m := the number of bits in x
        // S: O(n), n := the number of set bits in x
        while (x != 0) {
            ans += (x & 1);
            x >>= 1;  // In Java, use x >>>= 1 for unsigned shifting
        }
        */

        // Faster approach: drop the lowest set bit in each iteration
        // T: O(n)
        // S: O(n)
        while (x != 0) {
            x &= (x - 1);
            ++ans;
        }

        return ans;
    }
};
// @lc code=end

