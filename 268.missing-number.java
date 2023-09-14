/*
 * @lc app=leetcode id=268 lang=java
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
    // T: O(n * s), n := len(nums), s := no. of bits
    // S: O(s)
    public int missingNumber(int[] nums) {
        // For i from 0 to n - 1, if i exists in the array
        // somewhere, then the XOR of this number and itself
        // (i.e., an index) is 0. Do this XOR for all indices and
        // array elements, if there is a number not in the range(0, n),
        // the XOR result will reflect it since existing numbers and 
        // must have the corresponding array index.

        // init with array length because the max index is 1 less 
        // but the missing number might be the last number
        int ans = nums.length;
        for (int i = 0; i < nums.length; ++i) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
}
// @lc code=end

