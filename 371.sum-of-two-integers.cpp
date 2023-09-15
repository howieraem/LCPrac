/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    // Iterative solution
    // T: O(s), s := no. of bits
    // S: O(s)
    int getSum(int a, int b) {
        // a ^ b for 1+0, 0+1 and 0+0, ignoring 1+1 (but may involve carry from last iteration); 
        // a & b for 1+1 (carry, so shift left)
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;

            // left shifting a signed negative value in C++ is undefined behavior
            b = (unsigned)carry << 1;
        }
        return a;
    }

    /*
    // Recursive solution
    // T: O(s), s := no. of bits
    // S: O(s)
    int getSum(int a, int b) {
        // a ^ b for 1+0, 0+1 and 0+0, ignoring 1+1; 
        // a & b for 1+1 (carry, so shift left)
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
    */
};
// @lc code=end

