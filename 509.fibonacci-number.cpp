/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int fib(int n) {
        if (!n) return 0;
        int fn_2 = 0, fn_1 = 1;
        while (n-- > 1) {
            int tmp = fn_1;
            fn_1 += fn_2;
            fn_2 = tmp;
        }
        return fn_1;
    }
};
// @lc code=end

