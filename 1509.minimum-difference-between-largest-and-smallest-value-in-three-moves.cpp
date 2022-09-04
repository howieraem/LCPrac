/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */
#include <bits/stdc++.h>

using std::priority_queue;
using std::vector;
using std::greater;

// @lc code=start
class Solution {
public:
    // T: O(n * log(k)), k := the number of changes
    // S: O(k)
    int minDifference(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 4) return 0;

        // The answer is the minimum of the following 4 cases:
        // 1. change the top-3 values
        // 2. change the bottom-3 values
        // 3. change the top-2 and bottom-1 values
        // 4. change the bottom-2 and top-1 values

        /*
        // Intuitive: sort all numbers, T: O(n*log(n)), S: O(log(n))
        std::sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i < 4; ++i) {
            // minimum of (1st_max - 4th_min, 2nd_max - 3rd_min, 3rd_max - 2nd_min, 4th_max - 1st_min)
            ans = std::min(ans, nums[N - i - 1] - nums[4 - i - 1]);
        }
        */

        // Optimized: dynamically update the top-4 and bottom-4 numbers if there are more than 8 numbers
        if (N <= 8) {
            std::sort(nums.begin(), nums.end());
            int ans = INT_MAX;
            for (int i = 0; i < 4; ++i) {
                ans = std::min(ans, nums[N - i - 1] - nums[3 - i]);
            }
            return ans;
        }

        priority_queue<int> bottom;
        priority_queue<int, vector<int>, greater<int>> top;
        for (const int& x : nums) {
            top.push(x);
            bottom.push(x);
            if (top.size() > 4) top.pop();
            if (bottom.size() > 4) bottom.pop();
        }
        vector<int> extrema(8);
        // Be aware of the order in heap. For example, as in the loop above, the `bottom` 
        // heap popped the large numbers (i.e. not in the bottom-4), so the current top 
        // element of this heap is the 4th smallest element (rather than the 1st minimum).
        // Similarly for `top` heap.
        for (int i = 0; i < 4; ++i) {
            extrema[3 - i] = bottom.top(); bottom.pop();
            extrema[i + 4] = top.top(); top.pop();
        }

        int ans = INT_MAX;
        for (int i = 0; i < 4; ++i) {
            // minimum of (1st_max - 4th_min, 2nd_max - 3rd_min, 3rd_max - 2nd_min, 4th_max - 1st_min)
            ans = std::min(ans, extrema[7 - i] - extrema[3 - i]);
        }
        return ans;
    }
};
// @lc code=end

