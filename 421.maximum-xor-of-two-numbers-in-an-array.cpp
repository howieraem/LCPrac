/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * s), s := the number of bits of int type
    // S: O(n)
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, mask = 0;
        std::unordered_set<int> set;
        for (int i = 31; i >= 0; --i) {
            set.clear();

            // Set bits to 1 from most significant to least significant to mask out 
            // the less significant bits, i.e. "suffix", below
            mask |= (1 << i);
            for (const int& x : nums) {
                // Get the left (the more significant) bits of 
                // each number, i.e. "prefix"
                set.insert(x & mask);
            }

            // Try finding if there exists nums[i] ^ nums[j] such that 
            // there is one more bit 1 than the previous maximum.
            // If so, update the maximum so far.
            int tmp = ans | (1 << i);
            for (const int& prefix : set) {
                // a ^ b = c => a ^ a ^ b = a ^ c => 0 ^ b = a ^ c => a ^ c = b
                // If prefix_a ^ prefix_b = tmp, then prefix_a ^ tmp = prefix_b.
                // See if prefix_b exists in the hash set.
                if (set.find(tmp ^ prefix) != set.end()) {
                    ans = tmp;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

