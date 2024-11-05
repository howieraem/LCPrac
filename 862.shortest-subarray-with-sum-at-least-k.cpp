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
    // Prefix sum + mono deque
    // A more general scenario of Q209. Negative numbers exist.
    // Detailed explanations: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726
    // T: O(n)
    // S: O(n)
    int shortestSubarray(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans = n + 1;  // or INT_MAX
        vector<long> preSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        deque<int> q;  // keeps indexes of prefix sums ORDERED ASC

        for (int i = 0; i < n + 1; ++i) {
            // Keep preSums in queue increasing to make the subarray length shorter and its sum bigger.
            // Example: there are indexes x and y, such that x < y and preSum[x] >= preSum[y]. 
            // Now say preSum[x] <= preSum[i] - K for some index i. This implies preSum[y] <= preSum[x] <= preSum[i] - K. 
            // Hence the most greedy approach would be to choose y instead of x, since that minimizes subarr length.
            while (!q.empty() && preSum[q.back()] >= preSum[i]) {
                q.pop_back();
            }

            // For preSum[i], find the largest j such that preSum[j] - preSum[i] >= K
            // The subtracted prefix sum should be as small as possible
            while (!q.empty() && preSum[i] - preSum[q.front()] >= k) {
                ans = min(ans, i - q.front()); q.pop_front();
            }

            
            q.push_back(i);
        }
        
        // if ans >= n, it has not been updated in the loop above, meaning that there's no subarray sum >= k
        return ans <= n ? ans : -1;
    }

    /*
    Follow-up: longest subarray with sum at most k
    With negative numbers, the problem is that the sliding window sum is insufficient to 
    determine if we can stop at some r pointer or not. It's obviously possible that 
    there is a huge negative number after the current r pointer that will reduce the sum 
    to be below k and have a larger window. To account for this, we will track just one 
    more thing - For each index r, we will check if the remaining part of the array 
    (i.e., A[r+1:]) is negative or not.
    
    def longest_subarray_with_at_most_k(A, k):
        n = len(A)
        ans = 0 
        start = -1
        
        neg_suffix_sums = [0] * n   # non-positive
        cur_neg_suffix_sum = 0

        # Kadane's algo
        for r in range(n - 1, -1, -1):
            neg_suffix_sums[r] = cur_neg_suffix_sum
            cur_neg_suffix_sum = min(cur_neg_suffix_sum, 
                                     cur_neg_suffix_sum + A[r])
        
        ws = 0
        l = 0
        for r in range(n):
            ws += A[r]
            while l < r and ws + neg_suffix_sums[r] > k:
                ws -= A[l]
                l += 1
            
            new_len = r - l + 1
            if new_len > ans:
                ans = new_len
                start = l
        
        return (ans, A[start:start + ans]) if ans != 0 else (ans, [])
    */
};
// @lc code=end

