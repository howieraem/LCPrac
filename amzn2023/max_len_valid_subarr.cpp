/**
 * https://leetcode.com/discuss/interview-question/1636493
 * 
 * Given a list servers. Their processing power is given as a array of integer, and boot power as a array of integer.
 * Write a function to return the max length of subarray with power consumption <= max power limit.
 * Formula to calculate the power consumption for a subarray [i...j] is:
 *   max(boot_power[i...j]) + sum(process_power[i...j]) * (j - i)
 * 
 * Note: Single server is also a subarray, return 0 if no such subarray can be found.
 * 
 */
#include <bits/stdc++.h>

using std::vector;

// Similar to LC Q239: sliding window + mono deque, but window size is not fixed 
// and we need to find the maximum window size.
// T: O(n)
// S: O(n)
int max_len_valid_subarr(const vector<int>& process_power, const vector<int>& boot_power, int max_power) {
    std::deque<int> dq;
    int l = 0, r = 0;
    long windowed_sum = 0;
    int ans = 0;
    while (r < process_power.size()) {
        windowed_sum += process_power[r];
        while (!dq.empty() && boot_power[dq.back()] <= boot_power[r]) {
            // Update max(boot_power) inside the window
            dq.pop_back();
        }
        dq.push_back(r);

        while (l <= r && boot_power[dq.front()] + windowed_sum * (r - l + 1) > max_power) {
            // Shift the left boundary if total power too large
            if (dq.front() == l) {
                // The discarded machine might be has the max boot_power in 
                // the previous window, so need to update the deque as well.
                dq.pop_front();
            }
            windowed_sum -= process_power[l++];
        }
        ans = std::max(ans, r - l + 1);
        ++r;
    }
    return ans;
}
