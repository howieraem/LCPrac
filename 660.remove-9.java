/*
 * @lc app=leetcode id=660 lang=java
 *
 * [660] Remove 9
 */

// @lc code=start
class Solution {
    // The set of numbers without 9s is the same as the set of base-9 numbers, 
    // and they occur in the same order. The answer is therefore just the 
    // n-th base-9 number.
    // T: O(log9(n))
    // S: O(1)
    public int newInteger(int n) {
        int ans = 0, base = 1;
        while (n > 0) {
            int rem = n % 9;
            n /= 9;

            // What if remove 8, 7, etc.? The numbers will still be 9-base. 
            // However, some re-mapping is needed (e.g. map all 9's to 8's).
            // If the digit removed is d, then need to add the following line:
            // if(rem >= d) ++rem;

            ans = ans + rem * base;
            base *= 10;
        }
        return ans;
    }
}
// @lc code=end

