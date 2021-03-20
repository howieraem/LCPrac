/*
 * @lc app=leetcode.cn id=69 lang=java
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
    /*
    public int mySqrt(int x) {
        // Math definition: x^0.5 = exp(0.5*log(x))
        if (x == 0) {
            return 0;
        }
        int ans = (int)Math.exp(0.5 * Math.log(x));
        return (long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans;
    }

    public int mySqrt(int x) {
        // Binary search: find largest integer k such that k^2 <= x
        int left = 0, right = x, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long)mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    */

    
    public int mySqrt(int x) {
        // Newton method (1st and 2nd terms of Taylor Series). 
        // Usually faster than binary search but same time
        // complexity of O(log(x)).
        if (x == 0) {
            return 0;
        }

        double constant = x, x0 = x, xi;
        while (true) {
            xi = 0.5 * (x0 + constant / x0);
            if (Math.abs(x0 - xi) < 1e-6) {
                break;
            }
            x0 = xi;
        }
        return (int)x0;
    }
}
// @lc code=end

