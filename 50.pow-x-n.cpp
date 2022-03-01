/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    // T: O(log(n))
    // S: O(1)
    double myPow(double x, int n) {
        // Be careful when n = INT_MIN: cannot write 1.0 / helper(x, -n) for n < 0
        return n >= 0 ? helper(x, n) : 1.0 / x * 1 / helper(x, -(n + 1));
    }

private:
    double helper(double x, int n) {
        double ans = 1.0;
        while (n) {
            if (n & 1) {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end

