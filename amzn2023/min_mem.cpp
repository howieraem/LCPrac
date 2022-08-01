/**
 * Given a array, remove a subarray of length k such that the sum of the remaining elements is the minimum.
 * Return this minimum. 
 */
#include <climits>
#include <vector>

// T: O(n)
// S: O(1)
int min_sum_after_removal(const std::vector<int>& arr, int k) {
    int l = 0, r = 0;
    long long sum = 0, cur_windowed_sum = 0, max_windowed_sum = LONG_MIN;
    while (r < arr.size()) {
        sum += arr[r];
        cur_windowed_sum += arr[r++];
        if (r - l == k) {
            max_windowed_sum = std::max(max_windowed_sum, cur_windowed_sum);
            cur_windowed_sum -= nums[l++];
        }
    }
    return sum - max_windowed_sum;
}