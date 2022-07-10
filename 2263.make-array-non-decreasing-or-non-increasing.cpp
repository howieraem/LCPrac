/*
 * @lc app=leetcode id=2263 lang=cpp
 *
 * [2263] Make Array Non-decreasing or Non-increasing
 */
#include <bits/stdc++.h>

using std::vector;
using std::priority_queue;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    int convertArray(vector<int>& nums) {
        // Find the minimum costs to make `nums` non-decreasing and non-increasing respectively,
        // and then choose the minimum of the two costs.
        const int n = nums.size();
        int ops_inc = 0, ops_dec = 0;

        priority_queue<int> max_heap;

        // Non-decreasing case
        for (int i = 0; i < n; ++i) {
            if (max_heap.size() && max_heap.top() > nums[i]) {
                // We can choose to either increase nums[i] or decrease nums[i - 1].
                // In a greedy algorithm, we always choose to decrease nums[i - 1]. 
                // Need to push the new maximum to the queue.
                ops_inc += max_heap.top() - nums[i]; max_heap.pop();
                max_heap.push(nums[i]);
            }
            max_heap.push(nums[i]);
        }

        max_heap = priority_queue<int>();

        // Non-increasing case
        for (int i = n - 1; i >= 0; --i) {
            if (max_heap.size() && max_heap.top() > nums[i]) {
                ops_dec += max_heap.top() - nums[i]; max_heap.pop();
                max_heap.push(nums[i]);
            }
            max_heap.push(nums[i]);
        }
        return std::min(ops_inc, ops_dec);
    }
};
// @lc code=end
