#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Store indices instead of actual numbers, for convenient
        // simulation of a sliding window
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() <= i - k) {
                // shrink window by moving the left boundary
                q.pop_front();
            }

            while (!q.empty() && nums[i] > nums[q.back()]) {
                // mono-queue behavior: the indices of numbers
                // that are less than the current number will
                // be popped
                q.pop_back();
            }

            q.push_back(i);
            if (i >= k - 1) {
                // q.front() is always the array index of the maximum
                // element inside the window
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};