/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    long long subArrayRanges(std::vector<int>& nums) {
        const int n = nums.size();

        // Say there are x subarrays.
        // ans = (max_1 - min_1) + ... + (max_x - min_x)
        //     = -(min_1 + ... + min_x) + (max_1 + ... + max_x)
        long ans = 0;

        // -(min_1 + ... + min_x) is the negated sum of subarray minima (Q907).
        // Calculate -sum(nums[j] * f[j]), where f[j] is the number of 
        // subarrays with nums[j] as the minimum. Use a mono-stack to 
        // calculate f[j].
        std::stack<int> st;
        for (int right = 0; right <= n; ++right) {
            while (st.size() && (right == n || nums[st.top()] >= nums[right])) {
                int j = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                // `left` is the index of the 1st element less than nums[j] to the left,
                // and similar for `right`. f[j] = (right - j) * (j - left).
                ans -= (long) nums[j] * (right - j) * (j - left);
            }
            st.push(right);
        }

        // (max_1 + ... + max_x) is the sum of subarray maxima.
        // Calculate sum(nums[j] * f[j]), where f[j] is the number of 
        // subarrays with nums[j] as the maximum. Use a mono-stack to 
        // calculate f[j].
        st = std::stack<int>();
        for (int right = 0; right <= n; ++right) {
            while (st.size() && (right == n || nums[st.top()] < nums[right])) {
                int j = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                // `left` is the index of the 1st element greater than nums[j] to the left,
                // and similar for `right`. f[j] = (right - j) * (j - left).
                ans += (long) nums[j] * (right - j) * (j - left);
            }
            st.push(right);
        }

        return ans;
    }
};
// @lc code=end

