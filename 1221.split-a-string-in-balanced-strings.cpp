/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution {
public:
    // Greedy: Since the whole string is a balanced string, 
    // after we cut off a balanced substring, 
    // the remaing part will still be balanced.
    // T: O(n)
    // S: O(1)
    int balancedStringSplit(string s) {
        int ans = 0, diff = 0;
        for (const auto &c : s) {
            if (c == 'R') {
                ++diff;
            } else {
                --diff;
            }
            ans += (!diff);
        }
        return ans;
    }
};
// @lc code=end

