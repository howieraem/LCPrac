/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start
class Solution {
public:
    // O(1)
    int flipLights(int n, int presses) {
        // Doing operation 1 and then 2 is equivalent to doing operation 3 once, and hence:
        // op1 + op2 ==> op3; op1 + op3 ==> op2; op2 + op3 ==> op1
        // There are only 8 cases:
        // {all_on, op1, op2, op3, op4, op1+op4, op2+op4, op3+op4}
        if (!presses)  return 1;    // all_on
        if (n == 1)  return 2;      // all_on or all_off
        if (n == 2) {
            // presses == 1: all_on, first_on, second_on
            // presses > 1: cases in presses == 1 and all_off
            return presses == 1 ? 3 : 4;
        }
        if (presses == 1)  return 4;
        if (presses == 2)  return 7;
        return 8;   // can get all 8 cases with n > 2 and presses >= 3
    }
};
// @lc code=end

