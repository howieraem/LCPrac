/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // Sliding window:
    //     If A[l:r+1] has zeros <= K, we continue to increment r (expand window to the right).
    //     If A[l:r+1] has zeros > K, we increment l (shift the left boundary) as well as r.
    // T: O(n)
    // S: O(1)
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r;
        for (r = 0; r < nums.size(); ++r) {
            if (!nums[r])  --k;
            if (k < 0 && !nums[l++])  ++k;
        }
        return r - l;
    }
};
// @lc code=end

