/*
 * @lc app=leetcode id=1749 lang=cpp
 *
 * [1749] Maximum Absolute Sum of Any Subarray
 */
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

// @lc code=start
class Solution {
public:
    // The answer is the maximum prefix sum minus the minimum prefix sum
    // Proof: abs subarray sum = (prefix sum 1 - prefix sum 2) <= (max prefix sum - min prefix sum)
    // T: O(n)
    // S: O(1)
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, min_sum = 0, max_sum = 0;
        for (const int & x : nums) {
            sum += x;
            min_sum = min(min_sum, sum);
            max_sum = max(max_sum, sum);
        }
        return max_sum - min_sum;
    }
};
// @lc code=end

