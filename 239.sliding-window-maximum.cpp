/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include <deque>
#include <vector>

using std::deque;
using std::vector;

// @lc code=start
class Solution {
public:
    // Mono-deque + sliding window
    // T: O(n)
    // S: O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        deque<int> dq;   // stores indices of corresponding numbers ordered DESC
        vector<int> res;
        res.reserve(n - k + 1);  // there are n - k + 1 windows with size k

        for (int r = 0; r < n; ++r) {
            // slide the window, index of the previous maximum is outside the new window 
            if (!dq.empty() && dq.front() <= r - k) {
                dq.pop_front();
            }

            // dq.front() is the index of the maximum number
            // in the current sliding window
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if (r >= k - 1) {
                // start collecting results after the first window is formed
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end

