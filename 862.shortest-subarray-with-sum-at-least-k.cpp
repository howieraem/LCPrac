/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // A more general scenario of Q209. Negative numbers exist.
    // Detailed explanations: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726
    // T: O(n)
    // S: O(n)
    int shortestSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans = n + 1;
        vector<long> preSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        deque<int> q;  // keeps indexes of increasing prefix sums

        for (int i = 0; i < n + 1; ++i) {
            // For preSum[i], find the smallest j such that preSum[j] - preSum[i] >= K
            while (q.size() && preSum[i] - preSum[q.front()] >= k) {
                ans = min(ans, i - q.front()); q.pop_front();
            }

            // Make the subarray length shorter and its sum bigger.
            // No need to keep q.back():
            // preSum[future idx] - preSum[q.back()] >= k && preSum[q.back()] >= preSum[i]
            // Thus, preSum[future idx] - preSum[i] >= k
            while (q.size() && preSum[i] <= preSum[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        return ans <= n ? ans : -1;
    }
};
// @lc code=end

