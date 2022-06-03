/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
class Solution {
public:
    // Greedy:
    // Reduce target value as much as possible; if divisible by 2 
    // then divide by 2, else increment; if target becomes less than 
    // startValue, increment target.

    /*
    // Solution 1: Iterative
    // T: O(log(target - startValue))
    // S: O(1)
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue != target) {
            if (startValue < target) {
                if (target & 1) {
                    ++target;
                } else {
                    target >>= 1;
                }
                ++ans;
            } else {
                return ans + (startValue - target);
            }
        }
        return ans;
    }
    */

    // Solution 2: Recursive
    // T: O(log(target - startValue))
    // S: O(1) tail recursion?
    int brokenCalc(int startValue, int target) {
        if (startValue >= target)  return startValue - target;
        if (target & 1) {
            return 1 + brokenCalc(startValue, target + 1);
        }
        return 1 + brokenCalc(startValue, target >> 1);
    }
};
// @lc code=end

