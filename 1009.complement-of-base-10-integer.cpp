/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    // T: O(log(n))
    // S: O(1)
    int bitwiseComplement(int n) {
        // if (!n)  return 1;
        // int i = 0, mask = 0, num = n;
        // while (n) {
        //     mask |= (1 << i++);
        //     n >>= 1;
        // }
        // return mask ^ num;
        int a = 1;
        while (a < n) {
            a <<= 1;
            ++a;
        }
        // At this point, a's bits are all ones
        // so do XOR: 0 ^ 1 -> 1, 1 ^ 1 -> 0
        return n ^ a;
    }
};
// @lc code=end

