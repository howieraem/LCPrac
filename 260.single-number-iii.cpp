/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for (int x : nums) {
            s ^= x;
        }

        // At this point, s equals the xor of the two numbers that appear once respectively
        // Then, get the rightmost bit 1 of s.
        // The two numbers differ at this bit.
        // s &= ~(s - 1);  // be aware of overflow
        int mask = 1;
        while (!(s & mask)) {
            mask <<= 1;
        }
        s = mask;

        vector<int> res(2);
        for (int x : nums) {
            if (s & x) {
                // This bit is 1 for one of the target numbers as well as some other numbers appearing twice
                res[0] ^= x;
            } else {
                // This bit is 0 for one of the target numbers as well as some other numbers appearing twice
                res[1] ^= x;
            }
        }
        return res;
    }
};
// @lc code=end

