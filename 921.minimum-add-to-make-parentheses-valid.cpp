/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */
#include <string>

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int minAddToMakeValid(std::string s) {
        int missingLeft = 0, missingRight = 0;
        for (const auto &c : s) {
            if (c == '(') {
                missingRight++;
            } else {
                if (!missingRight) {
                    missingLeft++;
                } else {
                    missingRight--;
                }
            }
        }
        return missingLeft + missingRight;
    }
};
// @lc code=end

