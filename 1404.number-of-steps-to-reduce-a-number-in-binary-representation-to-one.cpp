/*
 * @lc app=leetcode id=1404 lang=cpp
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int numSteps(string s) {
        int ans = 0, carry = 0;
        for (auto i = s.size() - 1; i > 0; --i) {
            // If even, just shift right by one bit/char, so 1 operation.
            // If odd, need to add 1 to make it even, so 2 operations.
            ++ans;
            if (s[i] - '0' + carry == 1) {
                carry = 1;
                ++ans;
            }
        }
        ans += carry;
        return ans;
    }
};
// @lc code=end

