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
    // Mono-deque
    // T: O(n)
    // S: O(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        deque<int> dq;
        vector<int> res;
        res.reserve(n - k + 1);  // there are n - k + 1 windows with size k

        for (int i = 0; i < n; ++i) {
            // slide the window, index of the previous maximum is outside the new window 
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // dq.front() is the index of the maximum number
            // in the current sliding window
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1) {
                // start collecting results after the first window is formed
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end

