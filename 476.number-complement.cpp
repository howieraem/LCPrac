/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int i = 0, mask = 0, n = num;
        while (n) {
            mask |= (1 << i++);
            n >>= 1;
        }
        return mask ^ num;
    }
};
// @lc code=end

