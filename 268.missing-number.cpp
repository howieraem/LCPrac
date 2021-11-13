/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Bit manipulation. For i from 0 to n - 1, if i exists in the array
     * array somewhere, then the XOR of this number and this number
     * (i.e., the index) is 0. Do this XOR for all indices and
     * array elements, if there is a number not in the range(0, n),
     * the XOR result will reflect it.
     */
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
};
// @lc code=end

