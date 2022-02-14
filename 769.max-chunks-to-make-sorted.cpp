/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */
#include <algorithm>

using std::max;

// @lc code=start
class Solution {
public:
    // Slice when max(arr[:i+1]) == i. If not slicing here,
    // there will be an element greater than i in arr[:i+1]
    // and an element less than i in arr[i+1:], which will
    // NOT satisfy the required pattern of a sorted subarray 
    // (e.g. [0, 1, ..., i] or [i + 1, i + 2, ..., n - 1]).
    // T: O(n)
    // S: O(1)
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, max_right = INT_MIN;
        for (int i = 0; i < arr.size(); ++i) {
            max_right = max(max_right, arr[i]);
            ans += (max_right == i);
        }
        return ans;
    }
};
// @lc code=end

