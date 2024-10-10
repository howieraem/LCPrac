/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    // T: O(log(n)) number of bits of n
    // S: O(log(n))
    bool isPowerOfTwo(int n) {
        // key idea: pow(2, n) = (1 << n)
        return (n > 0) && (n & (n - 1)) == 0;
    }
};
// @lc code=end

