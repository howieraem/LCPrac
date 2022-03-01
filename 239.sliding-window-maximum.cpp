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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            // slide the window
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
                // start collecting results when the first window is formed
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end

